#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int, int> pii;
inline int read() {
    #ifndef gc
    #define gc() c=getchar()
    int x = 0, f = 0; char c; gc();
    for (; !isdigit(c); gc()) if (c == '-') f = 1;
    for (; isdigit(c); gc()) x = (x << 1) + (x << 3) + (c ^ '0');
    return f ? ~ x + 1: x;
    #endif
}
void solve () {
    int n, m; cin >> n >> m;
    #define pb push_back
    vector <int> A(n + 1), deg(n + 1);
    vector<vector<int> > vec(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> A[i];
    for (int i = 1; i <= m; i ++ ) {
        int u, v; cin >> u >> v;
        vec[u].pb(v); vec[v].pb(u);
        deg[u] ++ , deg[v] ++ ;
    }
    if (m % 2 == 0) cout << 0 << endl;
    else {
        int res = 1ll << 63 - 1;
        for (int i = 1; i <= n; i ++ ) {
            if (deg[i] % 2 == 1) res = min(res, A[i]);
            else for (int j = 0; j < vec[i].size(); j ++ ) if (deg[vec[i][j]] % 2 == 0) res = min(res, A[i] + A[vec[i][j]]);
        }
        cout << res << endl;
    }
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt -- )
        solve();
    return 0;
}