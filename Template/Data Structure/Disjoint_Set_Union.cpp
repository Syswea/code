#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int fa[N];
//fa[x] is characteristic number of x, parent node number, if fa[x] == x, x is root
//init fa[x] = x

int find (int x) {
    // return fa[x] == x? x : find (fa[x]); //preserve the path
    return fa[x] == x? x : fa[x] = find (fa[x]);//Recursive implementation of path compression
    // while (fa[x] != x) {
    //     fa[x] = fa[fa[x]];
    //     x = fa[x];
    // }
    // return x;//Iterative implementation of path compression
    //little diff with iterative and recursive
}

bool judge (int x, int y) {
    return find (x) == find (y);
}

void unite (int x, int y) {
    //if x and y in the same set, skip
    x = find (x), y = find (y);
    fa[x] = y;
}
