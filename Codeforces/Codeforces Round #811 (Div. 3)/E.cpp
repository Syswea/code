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
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve () {
    int n; cin >> n;
    vector<int> A(n);
    int is0 = 0, isn0 = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> A[i];
        if (A[i] % 10 == 0 || A[i] % 10 == 5) is0 ++ ;
        else isn0 ++ ;
    }
    if (is0 > 0 && isn0 > 0) cout << "NO" << endl;
    else {
        if (is0 > 0) {
            A[0] += A[0] % 10;
            string t = "YES";
            for (int i = 1; i < n; i ++ ) {
                A[i] += A[i] % 10;
                if (A[i] != A[i - 1]) t = "NO";
            }
            cout << t << endl;
        }
        else {
            for (int i = 0; i < n; i ++ )
                while (A[i] % 10 != 2) A[i] += A[i] % 10;
            string t = "YES";
            for (int i = 1; i < n; i ++ )
                if (abs(A[i] - A[i - 1]) % 20 != 0) t = "NO";
            cout << t << endl;
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
