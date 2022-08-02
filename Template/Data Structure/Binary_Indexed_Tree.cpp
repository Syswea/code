#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
struct BIT {
    int st[N];
    BIT() {memset(st, 0, sizeof st);};
    void add (int x, int y) {
        while (x <= n) st[x] += y, x += x & -x;
    }
    int sum(int x) {
        int res = 0;
        while (x) res += st[x], x -= x & -x;
        return res;
    }
    int query(int x, int y) {
        return sum(y) - sum(x - 1);
    }
} t = BIT();
signed main () {
    cin >> n >> m;
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