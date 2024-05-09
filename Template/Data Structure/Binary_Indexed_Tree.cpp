#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
struct BIT {
    int n;
    vector<int> C;
    BIT(int k) {
        n = k;
        C = vector<int>(n + 1, 0);
    }
    void add (int x, int y) {
        while (x <= n) C[x] += y, x += x & -x;
    }
    int sum(int x) {
        int res = 0;
        while (x) res += C[x], x -= x & -x;
        return res;
    }
    int query(int x, int y) {
        return sum(y) - sum(x - 1);
    }
};
signed main () {
    cin >> n >> m;
    BIT t = BIT(n);
    for (int i = 1, k; i <= n; i ++ ) {
        cin >> k;
        t.add(i, k);
    }
    while(m -- ) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) t.add(b, c);
        else {
            cout << t.query(b, c) << endl;
        }
    }
    return 0;
}
