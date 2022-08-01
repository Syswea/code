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
    int n, m; cin >> n >> m;
    vector<char> S(m);
    for (int i = 0; i < m; i ++ ) S[i] = 'B';
    for (int i = 0; i < n; i ++ ) {
        int x; cin >> x; -- x;
        if (S[min(x, m - 1 - x)] != 'A') S[min(x, m - 1 - x)] = 'A';
        else S[max(x, m - 1 - x)] = 'A';
    }
    for (auto x : S) cout << x ;
    cout << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt -- ) solve ();
    return 0;
}