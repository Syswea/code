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
    string s[n];
    map<string, int> mp;
    for (int i = 0; i < n; i ++ ) {
        cin >> s[i];
        mp[s[i]] = 1;
    }
    for (int i = 0; i < n; i ++ ) {
        int f = 0;
        for (int j = 1; j < s[i].size(); j ++ ) {
            string prefix = s[i].substr(0, j), suffix = s[i].substr(j, s[i].size() - j);
            if (mp[prefix] && mp[suffix]) f = 1;
        }
        cout << f ;
    }cout << endl;
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