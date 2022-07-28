#include <bits/stdc++.h>

using namespace std;

int h[N], v[N], nxt[N], idx;

const int N = 1e5 + 10, p = 1e5 + 7, null = 0x3f3f3f3f;
//null 开放寻址时不存在的数据

int has (int x) {
    return (x % p + p) % p;//负数要转换成正数
}

//存储结构
//开放寻址法
//多开线性数组长度
void init () {
    memset (h, 0x3f, sizeof h);
    //按照字节来 memset
}

int find (int x) {
    int k = has (x);//模数 p 为数量的2 ~ 3 倍的素数
    while (h[k] != null && h[k] != x) {
        k ++;
        if (k == p) k = 0;//循环查找空位
    }
    return k;
}
//x 在哈希表中 k 就是下标
//x 不在哈希表中 k 就是插入位置

void insert (int x) {
    int k = find (x);
    h[k] = x;
}

bool chk (int x) {
    int k = find (x);
    if (h[k] == null) return false;
    else return true;
}

//拉链法
//与邻接表存储相似
//链头就是hash值

void insert (int x) {
    v[idx] = x;
    nxt[idx] = h[has (x)];
    h[has (x)] = idx ++;
}
//查找就是遍历has (x)