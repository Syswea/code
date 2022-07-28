#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
const double eps = 1e-6;
//0 ~ N - 1 columns store a_1 ~ a_N N colum store b_i
double a[N][N];
int n;
int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c ++ ) {
        int t = r;
        for (int i = r; i < n; i ++ ) if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        if (fabs(a[t][c]) < eps) continue;
        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];
        for (int i = r + 1; i < n; i ++ )
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];
        r ++ ;
    }
    if (r < n) {
        for (int i = r; i < n; i ++ ) if (fabs(a[i][n] > eps)) return -1;   //none
        return 1;   //inf
    }
    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];
    return 0;   //only one
}
//a[i][n] store x_i
signed main () {
    return 0;
}