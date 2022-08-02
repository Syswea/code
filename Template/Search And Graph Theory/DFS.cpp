//permutation
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int vis[100], q[100];
void permutation(int k) {
    if (k == n) {
        for (int i = 0; i < n; i ++ ) cout << q[i] << ' ';
        cout << endl;
    }
    for (int i = 1; i <= n; i ++ )
        if (vis[i] == 0) {
            vis[i] = 1;
            q[k] = i;
            permutation(k + 1);
            vis[i] = 0;
        }
    return ;
}
signed main () {
    cin >> n;
    permutation(0);
    return 0;
}