#include <bits/stdc++.h>

using namespace std;

typedef long long  LL;

const int N = 100010;

int n,m;
int w[N];

struct node {
    int l, r;
    LL sum, add;
}tr[N << 2];

void pushup (int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    return ;
}

//单点修改不写pushdown
//modify和query不写pushdown就行了
void pushdown (int u) {
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.sum += (LL) (left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (LL) (right.r - right.l + 1) * root .add;
        root.add = 0;
    }
    return ;
}

void build (int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[r], 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build (u << 1, l, mid);
        build (u << 1 | 1, mid + 1, r);
        pushup (u);
    }
    return ;
}

void modify (int u, int l, int r, int d) {
    node &p = tr[u];
    if (p.l >= l && p.r <= r) {
        p.sum += (LL) (p.r - p.l + 1) * d;
        p.add += d;
    }
    else {
        pushdown (u);
        int mid = p.l + p.r >> 1;
        if (mid >= l) modify (u << 1, l, r, d);
        if (mid < r) modify (u << 1 | 1, l, r, d);
        pushup (u);
    }
    return ;
}

LL query (int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown (u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (mid >= l) sum += query (u << 1, l, r);
    if (mid < r) sum += query (u << 1 | 1, l, r);
    return sum;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
