//set Nim game
//multi SG graps
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110, M = 10010;
int n, m;
int s[N], f[M];
int sg(int x) {
    if (f[x] != -1) return f[x];
    set<int> st;
    for (int i = 0; i < m; i ++ ) if (x >= s[i]) st.insert(sg(x - s[i]));
    for (int i = 0; ; i ++ ) if(st.count(i) == 0) return f[x] = i;
}
signed main () {
    cin >> m;
    for (int i = 0; i < m; i ++ ) cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        int x; cin >> x;
        res ^= sg(x);
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}
/*
SG function : SG(end point) = 0;
    SG(x) = Mex(SG(y));
    x -> y;
Mex function : find the min num not belong the set, num is N*;
if SG(x) == 0 defeat
else victory

multi SG graphs
start point XOR sum;
sum == 0 defeat
else victory
*/
