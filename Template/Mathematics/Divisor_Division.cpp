#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> get_divisors(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; i ++ ) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    // sort(res.begin(), res.end());
    return res;
}
signed main () {
    return 0;
}