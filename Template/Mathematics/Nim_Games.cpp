#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    int n; cin >> n;
    vector<int> A(n);
    for (auto x : A) cin >> x;
    int res = 0;
    for (auto x : A) res ^= x;
    cout << res << endl;
    return 0;
}