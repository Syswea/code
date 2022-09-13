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
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i ++ ) cin >> A[i];
    int l = 0, r = (int) 1e9;
    while(l < r) {
        int x = l + r + 1 >> 1;
        int cnt = 0;
        auto B = A;
        for (int i = 0; i < n; i ++ ) if (2 * B[i] < x) B[i] = (int) 1e9, cnt ++ ;
        int one = 1, two = 1;
        for (int i = 0; i < n; i ++ ) {
            if (B[i] >= x) one = 0;
            if (i < n - 1 && min(B[i], B[i + 1]) >= x) two = 0;
        }
        cnt += one + two;
        if (cnt <= k) l = x;
        else r = x - 1;
    }
    cout << l << "\n";
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