#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
struct matrix {
    int columns, rows;
    int P[110][110];
    matrix(int c, int r) {columns = c, rows = r;}
    void inv() {
        for (int i = 1; i <= rows; i ++ ) P[i][i] = 1;
    }
    void init(int k) {
        for (int i = 1; i <= rows; i ++ ) for (int j = 1; j <= columns; j ++ ) P[i][j] = k;
    }
    matrix operator * (const matrix &X) {
        matrix res(columns, X.rows); res.init(0ll);
        for (int i = 1; i <= res.rows; i ++ )
            for (int j = 1; j <= res.columns; j ++ )
                for (int k = 1; k <= rows; k ++ )
                    res.P[i][j] = (res.P[i][j] + P[i][k] * X.P[k][j]) % mod;
        return res;
    }
    void print() {
        for (int i = 1; i <= rows; i ++ ) {
            for (int j = 1; j <= columns; j ++ )
                cout << P[i][j] << ' ';
            cout << endl;
        }
    }
};
matrix fp (matrix a, int n) {
    matrix res(a.columns, a.rows);
    res.inv();
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
};
signed main () {
    int N, K;
    cin >> N >> K;
    matrix A(N, N);
    for (int i = 1; i <= N; i ++ )
        for (int j = 1; j <= N; j ++ )
            cin >> A.P[i][j];
    auto RES = fp(A, K);
    RES.print();
    return 0;
}