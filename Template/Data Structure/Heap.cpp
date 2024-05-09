//heap小根堆
//priority_queue优先队列
#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq_greater;
priority_queue<int, vector<int>, greater<>()> pq_less;

const int N = 1e5 + 10;
int h[N], siz;
//start from 1

void down (int u) {
    int t = u;
    if (u * 2 <= siz && h[u * 2] < h[u]) t = u * 2;
    if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[u]) t = u * 2 + 1;
    if (t != u) {
        swap (h[t], h[u]);
        down (t);
    }
}

void up (int u) {
    while (u / 2 && h[u / 2] > h[u]){
        swap (h[u / 2], h[u]);
        u /= 2;
    }
}

void insert (int x) {
    h[++ siz] = x;
    up (siz);
}

int top () {
    return h[1];
}

void pop () {
    swap (h[1], h[siz --]);
    down (1);
}
