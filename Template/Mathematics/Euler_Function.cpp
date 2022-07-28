#include <bits/stdc++.h>
using namespace std;
#define int long long
//euler function
int euler(int N) {
    int res = N;
    for (int i = 2; i <= N / i; i ++ ) {
        if (N % i == 0) {
            res = res / i * (i - 1);
            while (N % i == 0) N /= i;
        }
    }
    if (N > 1) res = res / N * (N - 1);
    return res;
}
//euler function sieve
//i : 1 ~ n phi[i]
const int N = 1e5 + 9;
vector<int> primes;
int st[N], phi[N];
void get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i ++ ) {
        if (st[i] == 0) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ ){
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            else phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}
//A ^ phi[N] = 1 (mod N) A is primes to N :: Eular theorem
//A ^ (N - 1) = 1 (mod N) A is primes to N :: Fermat theorem
signed main () {
    return 0;
}