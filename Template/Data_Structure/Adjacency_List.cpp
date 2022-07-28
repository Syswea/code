#include <vector>

using namespace std;

const int N = 1e6 + 10, M = N << 1;

//vector实现
struct node {
    int to, v;
};
vector<node> vec[N];
//vec[x].push_back({y, v});

//链式向前星
int head[N], cnt = 0;
//head[x] 初始化为 -1
//cnt 相当于计数器

struct edge {
    int to, next, v;
}e[M];

void add (int x, int y, int v) {
    e[cnt] = {y, head[x], v};
    head[x] = cnt ++;
}