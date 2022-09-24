#include <bits/stdc++.h>
using namespace std;

const int N = 1010, p = 1e9 + 7;

int n;
int f[N][N];

int main () {
    cin >> n;
    // f[i][j] 1 ~ i kinds num to j
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            f[i][j] = f[i][j] + f[i][j - i];
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) ans += f[i][n];
    cout << ans << endl;
    return 0;
}
