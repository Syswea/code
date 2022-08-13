#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1.5e5 + 10;
int n, m;
int dist[N], vis[N];
typedef pair<int, int> pii;
#define x first
#define y second
vector<vector<pii>> vec(N + 1);
int dijkstra() {
    memset (dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        int t = pq.top().y;
        pq.pop();
        if (vis[t]) continue;
        vis[t] = 1;
        for (int i = 0; i < vec[t].size(); ++ i) {
            int tot = vec[t][i].x;
            int val = vec[t][i].y;
            if (dist[tot] > dist[t] + val) {
                dist[tot] = dist[t] + val;
                pq.push({dist[tot], tot});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f3f3f3f3f) return -1;
    return dist[n];
}
signed main () {
    cin >> n >> m;
    for (int i = 0; i < m; ++ i) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    cout << dijkstra() << "\n";
    return 0;
}