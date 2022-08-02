#include <bits/stdc++.h>
using namespace std;
#define int long long
int st[100010][25];
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> st[i][0];
    for (int j = 1; j <= 20; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    while(m -- ) {
        int l, r;
        cin >> l >> r;
        int k = log2(r - l + 1);
        cout << max(st[l][k], st[r - (1 << k) + 1][k]) << endl;
    }
    return 0;
}