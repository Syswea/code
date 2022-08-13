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
    int n; cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i ++ ) A[i] = i;
    cout << n << endl;
    for (int i = 1; i <= n; i ++ ) cout << A[i] << ' ' ;
    cout << endl;
    for (int j = 2; j <= n; j ++ ) {
        swap(A[j], A[j - 1]);
        for (int i = 1; i <= n; i ++ ) cout << A[i] << ' ' ;
        cout << endl;
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