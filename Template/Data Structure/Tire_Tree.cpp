//高效的存储和查找字符串集合的数据结构
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N][26], cnt[N], idx;

void insert (string s) {
    int p = 0;
    for (auto k : s) {
        int v = k - 'a';
        if (!a[p][v]) a[p][v] = ++idx;//记录节点编号
        p = a[p][v];
    }
    ++ cnt[p];
    return ;
}

int query (string s) {
    int p = 0;
    for (auto k : s) {
        int v = k - 'a';
        if (!a[p][v]) return 0;//空节点
        p = a[p][v];
    }
    return cnt[p];//以p为节点的单词个数
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