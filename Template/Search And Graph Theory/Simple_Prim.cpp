#include <bits/stdc++.h>
using namespace std;
#define int int64_t
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    const int inf = 0x3f3f3f3f3f3f3f3f;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, inf));
    while (m -- ) {
        int x, y, w;
        cin >> x >> y >> w;
        x -- , y -- ;
        a[x][y] = a[y][x] = min(a[x][y], w);
    }
    vector<int> dist(n, inf), vi(n, 0);
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (vi[j] == 0 && (t == -1 || dist[j] < dist[t]))
                t = j;
        if (i && dist[t] == inf) return cout << "impossible" << '\n', 0;
        if (i) res += dist[t];
        for (int j = 0; j < n; j ++ ) dist[j] = min(dist[j], a[t][j]);
        vi[t] = 1;
    }
    cout << res << '\n' ;
}