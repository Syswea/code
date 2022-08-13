#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 +10;
int n, m, k;
vector<int> x(N), y(N), w(N);
vector<int> dist(N, 0x3f3f3f3f3f3f3f3f);
void Bellman_Ford() {
    dist[1] = 0;
    for (int j = 0; j < k; ++ j) { //n times can get positive val shortest
        vector<int> backup = dist;
        for (int i = 0; i < m; ++ i)
            dist[y[i]] = min(dist[y[i]], backup[x[i]] + w[i]);
    }
    
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++ i)
        cin >> x[i] >> y[i] >> w[i];
    Bellman_Ford();
    if (dist[n] > 0x3f3f3f3f3f3f3f3f / 2) cout << "impossible" << "\n";
    else cout << dist[n] << "\n";
    return 0;
}