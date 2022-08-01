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
    int n, x; cin >> n >> x;
    vector<int> A(2 * n + 1);
    for (int i = 1; i <= 2 * n; i ++ ) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 1; i <= n; i ++ )
        if (A[i] + x > A[i + n]) {
            cout << "NO" << endl;
            return ;
        }
    cout << "YES" << endl;
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