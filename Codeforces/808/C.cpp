#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int, int> pii;
inline int read() {
    #ifndef gc
    #define gc() c = getchar()
    int x = 0, f = 0; char c; gc();
    for (; !isdigit(c); gc()) if (c == '-') f = 1;
    for (; isdigit(c); gc()) x = (x << 1) + (x << 3) + (c ^ '0');
    return f ? ~ x + 1: x;
    #endif
}
void sovle () {
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> A[i];
    vector<int> b(n + 1);
    int now_q = 0;
    for (int i = n; i >= 1; i -- ) {
        if (A[i] <= now_q) b[i] = 1;
        else if (now_q < q)  ++ now_q, b[i] = 1;
        else b[i] = 0;
    }
    for (int i = 1; i <= n; i ++ ) cout << b[i];
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