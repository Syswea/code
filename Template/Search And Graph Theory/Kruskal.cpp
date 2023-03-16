#include <bits/stdc++.h>
using namespace std;
#define int int64_t
signed main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> e(m);
    for (int i = 0; i < m; i ++ ) {
        int x, y, w;
        cin >> x >> y >> w;
        x -- , y -- ;
        e[i] = {w, {x, y}};
    }
    sort(e.begin(), e.end());
    vector<int> fa(n, 0);
    for (int i = 0; i < n; i ++ ) fa[i] = i;
    function<int(int)> find = [&](int x) {
        return fa[x] == x? x: fa[x] = find(fa[x]);
    };
    int res = 0, t = 0;
    for (int i = 0; i < m; i ++ ) {
        auto [w, k] = e[i];
        auto [x, y] = k;
        x = find(x), y = find(y);
        if (x == y) continue;
        res += w, fa[x] = y, t ++ ;
    }
    if (t < n - 1) cout << "impossible" << '\n' ;
    else cout << res << '\n' ;
}