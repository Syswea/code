#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int deg[N], vis[N];
int q[N], hh = 1, tt = 0;
vector<vector<int> > vec(N + 1);
//有重边有自环也适用
int main () {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i ++ ) {
        int u, v; cin >> u >> v;
        vec[u].push_back(v);
        deg[v] ++ ;
    }
    for (int i = 1; i <= n; i ++ )
        if (deg[i] == 0) q[ ++ tt] = i;
    while (hh <= tt) {
        int tmp = q[hh ++ ];
        for (int i = 0; i < vec[tmp].size(); i ++ ) {
            int tot = vec[tmp][i];
            deg[tot] -- ;
            if (deg[tot] == 0) q[ ++ tt] = tot;
        }
    }
    if (tt == n) for (int i = 1; i <= tt; i ++ ) cout << q[i] << ' ' ;
    else cout << -1 << endl;
    return 0;
}