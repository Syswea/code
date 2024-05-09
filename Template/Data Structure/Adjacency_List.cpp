#include <vector>

using namespace std;

const int N = 1e6 + 10, M = N << 1;

//Vector to solve
struct node {
    int to, v;
};
vector<node> vec[N];
//vec[x].push_back({y, v});

//Adjacency_List
int head[N], cnt = 0;
//head[x] init as -1
//cnt is counter

struct edge {
    int to, next, v;
}e[M];

void add (int x, int y, int v) {
    e[cnt] = {y, head[x], v};
    head[x] = cnt ++;
}