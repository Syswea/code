#include <bits/stdc++.h>
using namespace std;
int main () {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> e[n + 1];
    for (int i = 0; i < m; i ++ ) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> color(n + 1, 0);
    function<int(int, int)> dfs = [&](int u, int c) {
        color[u] = c;
        for (int v: e[u]) {
            if (color[v] == 0 && dfs(v, 3 - c) == 0) return 0;
            else if (color[v] == c) return 0;
        }
        return 1;
    };
    int f = 1;
    for (int i = 1; i <= n; i ++ )
        if (color[i] == 0 && dfs(i, 1) == 0) {
            f = 0;
            break;
        }
    cout << (f? "Yes": "No") << '\n' ;
}