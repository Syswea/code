#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int fp (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
signed main () {
    return 0;
}