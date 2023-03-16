#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;
signed main () {
   cin.tie(nullptr) -> sync_with_stdio(false);
   int n, m; cin >> n >> m;
   vector<pii> e[n];
   for (int i = 0; i < m; i ++ ) {
      int u, v, w;
      cin >> u >> v >> w;
      u -- , v -- ;
      e[u].push_back({v, w});
   }
  vector<int> vi(n, 0), dist(n, 0x3f3f3f3f3f3f3f);
  queue<int> q;
  dist[0] = 0, vi[0] = 1;
  q.push(0);
  while (q.size()) {
      int vec = q.front();
      q.pop();
      vi[vec] = 0;
      for (auto [x, w]: e[vec]) {
         if (dist[x] > dist[vec] + w) {
            dist[x] = dist[vec] + w;
            if (vi[x] == 0) q.push(x), vi[x] = 1;
         }
      }
  }
  if (dist[n - 1] > 0x3f3f3f3f3f3f3f / 2) cout << "impossible\n" ;
  else cout << dist[n - 1] << '\n' ;
   return 0;
}
