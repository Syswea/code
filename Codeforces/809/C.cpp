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
    int n; cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> A[i];
    if (n & 1) {
        int res = 0;
        for (int i = 2; i <= n - 1; i += 2)
            res += max(max(A[i - 1], A[i + 1]) + 1 - A[i], 0ll);
        cout << res << endl;
        return ;
    }
    else  {
        #define pb push_back
        vector<int> per, rep;
        per.pb(0);
        rep.pb(0);
        for (int i = 2; i <= n - 2; i += 2 )
            per.pb(per.back() + max(max(A[i - 1], A[i + 1]) + 1 - A[i], 0ll));
        for (int i = n - 1; i >= 3; i -= 2 )
            rep.pb(rep.back() + max(max(A[i - 1], A[i + 1]) + 1 - A[i], 0ll));
        int res = 1ll << 63 - 1;
        for (int i = 0; i <= (n - 1) / 2; i ++ )
            res = min(res, per[i] + rep[(n - 1) / 2 - i]);
        cout << res << endl;
        return ;
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