#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 40;
int n, m;
int p[N];
signed main () {
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> p[i];
    int res = 0;
    //binary enumeration
    for (int i = 1; i < 1 << m; i ++ ) {
        int t = 1, cnt = 0;
        for (int j = 0; j < m; j ++ )
            if (i << j & 1) {
                cnt ++ ;
                if (t * p[j] > n) {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        if (t != -1) {
            if (cnt & 1) res += n / t;
            else res -= n / t;
        }
    }
    cout << res << endl;
    return 0;
}