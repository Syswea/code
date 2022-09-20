//Stone amalgamation
#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int n;
int A[N], f[N][N];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    for (int k = 2; k <= n; k ++ ) {
        for (int i = 1; i + k - 1 <= n; i ++ ) {
            int j = i + k - 1;
            f[i][j] = 0x3fffff;
            for (int t = i; t < j; t ++ ) {
                f[i][j] = min(f[i][j], f[i][t] + f[t + 1][j] + A[j] - A[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}