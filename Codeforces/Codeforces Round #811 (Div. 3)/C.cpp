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
    int s; cin >> s;
    int a[10], cnt = 0;
    for (int i = 9; i >= 1 && s > 0; i -- ) {
        if (s > i) s -= i, a[ ++ cnt] = i;
        else a[ ++ cnt] = s, s = 0;
    }
    for (int i = cnt; i >= 1; i -- ) cout << a[i] ;
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