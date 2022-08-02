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
    set<string> st;
    int xmax = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> s[i];
        st.insert(s[i]);
    }
    for (int k = 0; k < n; k ++ ) {
        int t = 0;
        for (int i = 0; i < n; i ++ ) {
            if (i == k || s[i].size() > s[k].size()) continue;
            int f = 0;
            for (int j = 0; j < s[i].size(); j ++ )
                if (s[i][j] != s[k][j]) f = 1;
            if (f) continue;
            string tmp = "";
            int cnt = 0;
            for (int j = s[i].size(); j < s[k].size(); j ++ ) tmp += s[k][j];
            if (st.find(tmp) != st.end()) t = 1;
        }
        cout << t ;
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