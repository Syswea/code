#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(n), s(n);
    int dp[n + 1][m + 1];
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k ++ ) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}