const int N = 1e6 + 10;

//似乎也是双端队列
//队列
int q[N], hh = 1, tt = 0;//tt - hh + 1是元素个数
//x加入队列
void insert (int x) {
    q[++ tt] = x;
}
//队头元素
int back () {
    return q[hh];
}
int front () {
    return q[tt];
}
//队头元素出队
void pop () {
    hh ++;
}
//元素个数
int size() {
    return tt - hh + 1;
}
//判断非空
bool notempty () {
    return hh <= tt;
}
