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
void sovle () {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int x = l / i, y = r / i;
        if (l % i == 0) A[i] = l;
        else if (r % i == 0) A[i] = r;
        else {
            if (x == y) {
                cout << "NO" << endl;
                return ;
            }
            else {
                A[i] = y * i;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i ++ ) cout << A[i] << ' ';
    cout << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt -- )
        sovle();
    return 0;
}