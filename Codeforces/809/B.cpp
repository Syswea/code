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
    #define pb push_back
    int n; cin >> n;
    vector<vector<int> > vec(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int x; cin >> x;
        if (vec[x].size() == 0) vec[x].pb(0);
        vec[x].pb(i);
    }
    for (int k = 1; k <= n; k ++ ) {
        auto a = vec[k];
        if (a.size() == 0) {
            cout << 0 << ' ' ;
            continue;
        }
        vector<int> dp(a.size()); dp[0] = 0;
        int i = 0, j = 0;
        for (int t = 1; t < a.size(); t ++ ) {
            if (a[t] & 1) dp[t] = max(dp[t], dp[j] + 1), i = t;
            else dp[t] = max(dp[t], dp[i] + 1), j = t;
        }
        cout << dp[a.size() - 1] << ' ';
    }
    cout << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt -- )
        solve();
    return 0;
}