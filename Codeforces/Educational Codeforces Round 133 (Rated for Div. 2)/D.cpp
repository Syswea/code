#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int, int> pii;
int fp(int a, int n) {int res = 0; while (n) {if (n & 1) res = res * a; a = a * a; n >>= 1;} return res;}
inline int read() {
    #ifndef gc
    #define gc() c=getchar()
    int x = 0, f = 0; char c; gc();
    for (; !isdigit(c); gc()) if (c == '-') f = 1;
    for (; isdigit(c); gc()) x = (x << 1) + (x << 3) + (c ^ '0');
    return f ? ~ x + 1: x;
    #endif
}
const int p = 998244353;
void solve () {
    int n, k; cin >> n >> k;
    vector<int> f(n + 1, 0), g(n + 1, 0);
    vector<int> ans(n + 1, 0);
    int sum = 0;
    g[0] = 1;
    for (int t = k; t <= n; t ++ ) {
        if (sum > n) break;
        for (int i = 0; i < sum; i ++ ) f[i] = 0;
        for (int i = sum; i <= n; i ++ ) {
            if (i - t >= 0)
                f[i] = (f[i - t] + g[i - t]) % p;
            else f[i] = 0;
            ans[i] = (ans[i] + f[i]) % p;
        }
        for (int i = 0; i <= n; i ++ ) g[i] = f[i];
        sum += t;
    }
    for (int i = 1; i <= n; i ++ ) cout << ans[i] << " \n"[i == n];
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int tt; cin >> tt;
    // while (tt -- )
        solve();
    return 0;
}