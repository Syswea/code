#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int fa[N];
//fa[x] 为 x 的特征数字,父节点编号,当fa[x] == x时 x 为根节点
//初始化 fa[x] = x

int find (int x) {
    // return fa[x] == x? x : find (fa[x]);//保留路径
    return fa[x] == x? x : fa[x] = find (fa[x]);//路径压缩的递归写法
    // while (fa[x] != x) {
    //     fa[x] = fa[fa[x]];
    //     x = fa[x];
    // }
    // return x;//路径压缩的递推写法
    //递推递归影响不大
}

bool judge (int x, int y) {
    return find (x) == find (y);
}

void unite (int x, int y) {
    //当 x, y已经在一个集合里面了有时需要跳过
    x = find (x), y = find (y);
    fa[x] = y;
}
