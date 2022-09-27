#include <bits/stdc++.h>
using namespace std;

const int N = 1010, p = 1e9 + 7;

int main () {

    int n;
    int f[N];

    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            f[j] = (f[j] + f[j - i]) % p;
    cout << f[n] << endl;
    return 0;
}

int main () {

    int n;
    int f[N][N];

    cin >> n;
    f[1][1] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ ) {
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % p;
        }
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = (res + f[n][i]) % p;
    cout << res << endl;
    return 0;
}