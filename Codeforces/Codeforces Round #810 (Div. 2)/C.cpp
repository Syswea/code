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
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(k + 1);
    for (int i = 1; i <= k; i ++ ) cin >> A[i];
    int cnt = 0;
    int xmax = 0;
    for (int i = 1; i <= k; i ++ ) {
        int t = A[i] / n;
        xmax = max(xmax, t);
        if (t >= 2) cnt += t;
    }
    if (cnt >= m) {
        if (m % 2 == 0 || xmax >= 3) {
            cout << "YES" << endl;
            return ;
        }
    }
    cnt = 0;
    xmax = 0;
    for (int i = 1; i <= k; i ++ ) {
        int t = A[i] / m;
        xmax = max(xmax, t);
        if (t >= 2) cnt += t;
    }
    if (cnt >= n) {
        if (n % 2 == 0 || xmax >= 3) {
            cout << "YES" << endl;
            return ;
        }
    }
    cout << "NO" << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt -- )
        solve ();
    return 0;
}