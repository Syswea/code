#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m, q;
int a[N], b[N];
int g[N][N];
//一维差分
//作用是区间修改
void insert (int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
    return ;
}
//二维差分
//构造为插入差分
//查询为前缀
void insert (int x1, int y1, int x2, int y2, int c) {
    g[x1][y1] += c;
    g[x2 + 1][y1] -= c;
    g[x1][y2 + 1] -= c;
    g[x2 + 1][y2 + 1] += c;
    return ;
}
void print () {
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ ) {
            g[i][j] = g[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
            printf ("%d ", g[i][j]);
        }
}
int main () {
    scanf ("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ )
            scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) insert (i, i, a[i]);
    int l, r, c;
    while (m --) {
        scanf ("%d%d%d", &l, &r, &c);
        insert (l, r, c);
    }
    for (int i = 1; i <= n; i ++ ) {
        b[i] += b[i - 1];
        printf ("%d ", b[i]);
    }
    return 0;
}