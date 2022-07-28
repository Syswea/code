//单调队列保存数组下标用来判断是否越界
//一定记得判断非空才能操作
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;

int n, k;
int a[N];
int q[N];
int hh = 1, tt = 0;

int main () {
    ios::sync_with_stdio (false);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = 1; i < k; i ++ ) {
        while (i - q[hh] >= k && hh <= tt) ++ hh;//出队时判断是否为空
        while (a[q[tt]] >= a[i] && hh <= tt) -- tt;
        q[++ tt] = i;
    }
    for (int i = k; i <= n; i ++ ) {
        while (i - q[hh] >= k && hh <= tt) ++ hh;
        while (a[q[tt]] >= a[i] && hh <= tt) -- tt;
        q[++ tt] = i;
        cout << a[q[hh]] << ' ';
    }
    //也可以都保存下来
    // for (int i = 1; i < k; i ++ ) {
    //     while (i - q[hh].second >= k && hh <= tt) ++ hh;
    //     while (q[tt].first >= a[i] && hh <= tt) -- tt;
    //     q[++ tt] = {a[i], i};
    // }
    // for (int i = k; i <= n; i ++ ) {
    //     while (i - q[hh].second >= k && hh <= tt) ++ hh;
    //     while (q[tt].first >= a[i] && hh <= tt) -- tt;
    //     q[++ tt] = {a[i], i};
    //     cout << q[hh].first << ' ';
    // }

    cout << endl;

    hh = 1, tt = 0;//初始化
    for (int i = 1; i < k; i ++ ) {
        while (i - q[hh] >= k && hh <= tt) ++ hh;
        while (a[q[tt]] <= a[i] && hh <= tt) -- tt;
        q[++ tt] = i;
    }
    for (int i = k; i <= n; i ++ ) {
        while (i - q[hh] >= k && hh <= tt) ++ hh;
        while (a[q[tt]] <= a[i] && hh <= tt) -- tt;
        q[++ tt] = i;
        cout << a[q[hh]] << ' ';
    }
    return 0;
}