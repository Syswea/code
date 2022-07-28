#include <bits/stdc++.h>
using namespace std;
#define int long long
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i ++ ) if (n % i == 0) return false;
    return true;
}
signed main () {
    return 0;
}