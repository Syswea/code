#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char s[N], p[M];
int nxt[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> s + 1;
    cin >> m >> p + 1;

    //求前缀数组
    //j为已经匹配好的最后位置
    //j + 1为带匹配的字符
    for (int i = 2, j = 0; i <= n; i ++ ) {
        while (j && s[i] != s[j + 1]) j = nxt[j];
        //递归求解
        //并不是与i - 1进行匹配
        //而是与前缀匹配的地方继续匹配
        if (s[i] == s[j + 1]) j ++;
        nxt[i] = j;
    }//自我匹配的KMP

    for (int i = 1, j = 0; i <= m; i ++ ) {
        while (j && p[i] != s[j + 1]) j = nxt[j];
        //如果不匹配就递归查询
        if (p[i] == s[j + 1]) j ++;
        if (j == n) {//查询到了s字符串的尾部
            cout << i - j << ' ';
            j = nxt[j];
        }
    }
    return 0;
}