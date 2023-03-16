#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int a[210][210];
const int inf = 0x3f3f3f3f3f3f3f3f;
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) a[i][j] = 0;
            else a[i][j] = inf;
    while (m -- ) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x][y] = min(a[x][y], w);
    }
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    while (k -- ) {
        int x, y; cin >> x >> y;
        if (a[x][y] > inf / 2) cout << "impossible" << '\n' ;
        else cout << a[x][y] << '\n' ;
    }
}