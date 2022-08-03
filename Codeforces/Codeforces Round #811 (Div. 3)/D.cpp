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
void solve () {
    string t, s[11];
    cin >> t;
    int n; cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> s[i];

    int ans[110];
    int vis[110] = {};
    memset(ans, 0x1231, sizeof ans);
    ans[0] = 0, vis[0] = 1;

    int cas[110], bf[110];
    bf[0] = -1;

    for (int tmp = 0; tmp < t.size(); tmp ++ ) {
        for (int i = 0; i < n; i ++ ) {
            int f = 1;
            for (int k = 0; k < s[i].size(); k ++ ) {
                if (tmp + k >= t.size() || t[tmp + k] != s[i][k]) f = 0;
            }
            if (f == 0) continue;
            if (vis[tmp] == 0) continue;
            int k = tmp + s[i].size();
            for (int j = tmp + 1; j <= k && j <= t.size(); j ++ ) {
                if (vis[j] == 0) {
                    ans[j] = ans[tmp] + 1;
                    cas[j] = i;
                    bf[j] = tmp;
                }
                else {
                    if (ans[tmp] + 1 < ans [j]) {
                        ans[j] = ans[tmp] + 1;
                        cas[j] = i;
                        bf[j] = tmp;
                    }
                }
                vis[j] = 1;
            }
        }
    }
    if (vis[t.size()] == 0)
        cout << -1 << endl;
    else {
        cout << ans[t.size()] << endl;
        int cnt = ans[t.size()];
        for (int i = t.size(); i >= 0 && cnt -- ; i = bf[i]) {
            int t = cas[i];
            cout << t + 1 << ' ' << bf[i] + 1 << endl;
        }
    }
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