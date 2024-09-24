#include <bits/stdc++.h>
using namespace std;

//  n vertices m directed edges
int n, m;
// e[u].v: has a edge from u to v
vector<vector<int>> e;

int idx = 0, sc = 0;
// dfn: order in dfs
// low: mini dfn in subtree pass "at most one back edge"
// scc[i]: vertex i in scc i
// sz: the number of scc
vector<int> dfn, low, scc, sz;

int top = 0;
vector<int> in, sta;

vector<int> w, d;

void tarjan(int u) {
  dfn[u] = low[u] = ++idx;
  sta[++top] = u, in[u] = 1;
  for (const auto &v : e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

  if (dfn[u] == low[u]) {
    sc++;
    for (int f = 0, x; !f; f |= x == u) {
      x = sta[top--];
      sz[sc]++, scc[x] = sc, in[x] = 0;
    }
  }
}

int main() {
  cin >> n >> m;

  w.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> w[i];

  e.resize(n + 1);

  dfn.resize(n + 1, 0);
  low.resize(n + 1, 0);
  scc.resize(n + 1, 0);
  sz.resize(n + 1, 0);

  in.resize(n + 1, 0);
  sta.resize(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    e[u].push_back(v);
    // e[v].push_back(u); // for no-direct edge
  }

  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }

  // toposort
  d.resize(n + 1, 0);
  vector<int> ee[sc + 1], dp(sc + 1, 0), deg(sc + 1, 0);

  for (int i = 1; i <= n; i++) d[scc[i]] += w[i];

  for (int i = 1; i <= n; i++) {
    int x = scc[i];
    for (auto v : e[i]) {
      int y = scc[v];
      if (x != y) ee[x].push_back(y), deg[y]++;
    }
  }

  queue<int> que;
  for (int i = 1; i <= sc; i++) {
    if (deg[i] == 0) que.push(i), dp[i] = d[i];
  }

  while (que.size()) {
    auto u = que.front();
    que.pop();
    for (auto v : ee[u]) {
      dp[v] = max(dp[v], dp[u] + d[v]);
      if (--deg[v] == 0) que.push(v);
    }
  }

  int ans = 0;
  for (int i = 1; i <= sc; i++) ans = max(ans, dp[i]);

  cout << ans << '\n';
}