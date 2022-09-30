#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p = 1e9 + 7, N = 2010;
//dp
vector<vector<int> > case1 (int n) {
    vector<vector<int> > c(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (j == 0 || i == j) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1] % p;
    return c;
}
//fact
int fp(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}
void case2 (int n) {
    vector<int> fact(n), infact(n);
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        fact[i] = fact[i - 1] * i % p;
        infact[i] = infact[i - 1] * fp(i, p - 2) % p;
    }
    return ;
}
//Lucas
//fact calc C_a^b
int C(int a, int b) {
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++ , j -- ) {
        res = res * j % p;
        res = res * fp(i, p - 2) % p;
    }
    return res;
}
//recursion
int lucas(int a, int b) {
    if (a < p && b < p) return C(a, b);
    return C(a % p, b % p) * lucas(a / p, b / p);
}
signed main () {
    return 0;
}