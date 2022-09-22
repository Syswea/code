#include <bits/stdc++.h>
using namespace std;

const int N = 1010, p = 1e9 + 7;

int n;
int f[N][N];

int main () {
    cin >> n;
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            f[i][j] = f[i - 1][j] + f[i][j - i];
    cout << f[n][n] << endl;
    return 0;
}
