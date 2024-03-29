#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 1e5 + 10, P = 131;// P = 13331;

int n, m;
char str[N];
ull p[N], h[N];

ull get (int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main () {
    cin >> n >> m >> str + 1;

    p[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];//自然溢出
    }

    while (m -- ) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get (l1, r1) == get (l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}
