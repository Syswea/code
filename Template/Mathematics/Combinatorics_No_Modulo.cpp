#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> getprimes(int n) {
    vector<int> res, st(n + 1);
    for (int i = 2; i <= n; i ++ ) {
        if (st[i] == 0) res.push_back(i);
        for (int j = 0; res[j] <= n / i; j ++ ) {
            st[res[j] * i] = 1;
            if (i % res[j] == 0) break;
        }
    }
    return res;
}

int get(int a, int p) {
    int res = 0;
    while (a) {
        res += a / p;
        a /= p;
    }
    return res;
}
vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for (int x : a) {
        t += x * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

signed main () {
    int a, b;
    cin >> a >> b;
    vector<int> sum;
    auto primes = getprimes(a);
    for (int p : primes)
        sum.push_back(get(a, p) - get(b, p) - get(a - b, p));
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < primes.size(); i ++ )
        for (int j = 0; j < sum[i]; j ++ )
            res = mul(res, primes[i]);
    reverse(res.begin(), res.end());
    for (int x : res) cout << x ;
    return 0;
}