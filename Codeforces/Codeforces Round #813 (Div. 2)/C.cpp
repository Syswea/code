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
    map<int, int> mp;
    vector<int> kin(n + 1, 0);
    for (int i = 1; i <= n; i ++ ) {
        cin >> A[i];
        if (mp.empty() || mp.find(A[i]) == mp.end())
            kin[i] = kin[i - 1] + 1;
        else kin[i] = kin[i - 1];
        mp[A[i]] = i;
    }
    function<int(int, int)> dfs = [&](int end, int sta) {
        int maximum = sta;
        for (int i = sta; i > end; i -- )
            maximum = max(mp[A[i]], maximum);
        if (maximum > sta) return dfs(sta, maximum);
        else return sta;
    };
    int k = -1;
    for (int i = n; i > 1; i -- ) if (A[i - 1] > A[i]) {k = i - 1; break;}
    if (k == -1) cout << 0 << "\n";
    else {
        int t = dfs(0, k);
        cout << kin[t] << "\n";
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