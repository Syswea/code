#include <bits/stdc++.h>
using namespace std;
signed main () {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N, M, S;
    cin >> N >> M >> S;
    vector<vector<int>> E(N + 1);
    for (int i = 1; i < N; i ++ ) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<vector<int>> Anc(N + 1, vector<int>(21));
    vector<int> Dep(N + 1);
    function<void(int, int)> Get_Ancestor = [&] (int par, int i) {
        Dep[i] = Dep[par] + 1;
        Anc[i][0] = par;
        for (int j = 1; j <= 20; j ++ )
            Anc[i][j] = Anc[Anc[i][j - 1]][j - 1];
        for (int j : E[i]) if (j != par) Get_Ancestor(i, j);
        return ;
    };
    Get_Ancestor(0, S);
    function<int(int, int)> Get_LCA = [&] (int u, int v) {
        if (Dep[u] < Dep[v]) swap(u, v);
        for (int j = 20; j >= 0; j -- )
            if (Dep[Anc[u][j]] >= Dep[v]) u = Anc[u][j];
        if (u == v) return u;
        for (int j = 20; j >= 0; j -- )
            if (Anc[u][j] != Anc[v][j]) u = Anc[u][j], v = Anc[v][j];
        return Anc[u][0];
    };
    while (M -- ) {
        int u, v;
        cin >> u >> v;
        cout << Get_LCA(u, v) << "\n";
    }
    return 0;
}