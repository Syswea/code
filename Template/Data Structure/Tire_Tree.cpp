// An efficient data structure for storing and querying a set of strings
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N][26], cnt[N], idx;

void insert (string s) {
    int p = 0;
    for (auto k : s) {
        int v = k - 'a';
        if (!a[p][v]) a[p][v] = ++idx;// Record the node number
        p = a[p][v];
    }
    ++ cnt[p];
    return ;
}

int query (string s) {
    int p = 0;
    for (auto k : s) {
        int v = k - 'a';
        if (!a[p][v]) return 0;// Empty node
        p = a[p][v];
    }
    return cnt[p];// Number of words with p as the node
}

int n;
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    cin >> n;
    char c;
    string s;
    while (n -- ) {
        cin >> c >> s;
        if (c == 'I') insert (s);
        else cout << query (s) << endl;
    }
    return 0;
}