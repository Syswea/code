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
    int n, c, q; cin >> n >> c >> q;
    string s; cin >> s;
    s =  ' ' + s;
    int l[c + 1], r[c + 1];
    l[0] = 0, r[0] = n - 1;
    for (int i = 1; i <= c; i ++ ) {
        cin >> l[i] >> r[i];
    }
    while (q -- ) {
        int k; cin >> k;
        while (k > n) {
            for (int i = 0; i <= c; i ++ ) {
                int len = r[i] - l[i] + 1;
                if (k > len) k -= len;
                else {
                    k = l[i] + k - 1;
                    break;
                }
            }
        }
        cout << s[k] << endl;
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