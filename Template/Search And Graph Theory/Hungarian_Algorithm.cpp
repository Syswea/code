#include <bits/stdc++.h>
using namespace std;
#define int int64_t
signed main () {
   cin.tie(0) -> sync_with_stdio(0);
   int n1, n2, m;
   cin >> n1 >> n2 >> m;
   vector<int> e[n1 + 1];
   while (m -- ) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
   }
   vector<int> st(n2 + 1, 0), match(n2 + 1, 0);
   function<int(int)> find = [&](int u) {
      for (int v: e[u]) {
         if (st[v] == 0) {
            st[v] = 1;
            if (match[v] == 0 || find(match[v])) {
               match[v] = u;
               return true;
            }
         }
      }
      return false;
   };
   int res = 0;
   for (int i = 1; i <= n1; i ++ ) {
      st = vector<int>(n2, 0);
      if (find(i)) res ++ ;
   }
   cout << res << '\n' ;
}