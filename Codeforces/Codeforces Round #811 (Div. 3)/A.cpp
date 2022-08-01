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
    pair<int, int> slp;
    int n; cin >> n >> slp.x >> slp.y;
    pair<int, int> t[n];
    for (int i = 0; i < n; i ++ ) cin >> t[i].x >> t[i].y;
    sort(t, t + n);
    for (int i = 0; i < n; i ++ ) {
        if (t[i] == slp) {
            cout << "0 0" << endl;
            return ;
        }
        if (t[i] > slp) {
            int a = t[i].x - slp.x;
            int b = t[i].y - slp.y;
            if (b < 0) b += 60, a -= 1;
            cout << a << ' ' << b << endl;
            return ;
        }
        if (i == n - 1) {
            int a = t[0].x - slp.x + 24;
            int b = t[0].y - slp.y;
            if (b < 0) b += 60, a -= 1;
            cout << a << ' ' << b << endl;
            return ;
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