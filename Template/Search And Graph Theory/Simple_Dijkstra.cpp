#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510;
int n, m;
int g[N][N], dist[N], vis[N];
int dijkstra() {
    memset (dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= n; ++ i) {
        int t = -1;
        for (int j = 1; j <= n;  ++ j)
            if (vis[j] == 0 && (t == -1 || dist[t] > dist[j]))
                t = j;
        vis[t] = 1;
        for (int j = 1; j <= n; ++ j) 
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f3f3f3f3f) return -1;
    return dist[n];
}
signed main () {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++ i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << "\n";
    return 0;
}