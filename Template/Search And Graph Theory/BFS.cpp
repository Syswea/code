#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 110;
int n, m;
int g[N][N], d[N][N];
pii q[N * N];
signed main () {
    cin >> n >> m; 
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];
    int hh = 1, tt = 0;
    q[++ tt] = {0, 0};
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while (hh <= tt) {
        auto t = q[hh ++ ];
        for (int k = 0; k < 4; k ++ ) {
            int x = t.x + dx[k], y = t.y + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.x][t.y] + 1;
                q[++ tt] = {x, y};
            }
        }
    }
    cout << d[n - 1][m - 1] << endl;
    return 0;
}