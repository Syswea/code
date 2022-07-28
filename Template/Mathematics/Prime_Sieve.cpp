#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
vector<int> primes;
bool st[N];
void era_sieve(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (st[i] == 0) {
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}
void euler_sieve(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (st[i] == 0) primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
signed main () {
    return 0;
}