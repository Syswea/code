#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 110;

int n, m;
int v[N], w[N], s[N];

int one_dimensional () {
    int dp[M] = {};
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= 0; j -- )
            for (int k = 1; k <= s[i] && j >= k * v[i]; k ++ )
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
    return dp[m];
}

int two_dimensional () {
    int dp[N][M] = {};
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k ++ ) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    return dp[n][m];
}

int main () {
    cin >> n >> m;
    // for (int i = 1; i <= n; i ++ )
    //     cin >> v[i] >> w[i] >> s[i];

    //binary grouping
    vector<int> v, w;
    for (int i = 1; i <= n; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        int k = 1;
        while (k <= c) {
            v.push_back(k * a);
            w.push_back(k * b);
            c -= k;
            k <<= 1;
        }
        if (c > 0) {
            v.push_back(c * a);
            w.push_back(c * b);
        }
    }
    int dp[2010] = {};
    for (int i = 0; i < (int)v.size(); i ++ )
        for (int j = m; j >= v[i]; j -- )
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[m] << endl;
    return 0;
}