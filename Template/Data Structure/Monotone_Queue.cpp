//A monotonic queue is used to store array indices to determine whether it is out of bounds
//Always remember to check for non-empty before performing operations
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
        while (i - q[hh] >= k && hh <= tt) ++ hh;//Check for emptiness when dequeuing
        while (a[q[tt]] >= a[i] && hh <= tt) -- tt;
        q[++ tt] = i;
    }
    for (int i = k; i <= n; i ++ ) {
        while (i - q[hh] >= k && hh <= tt) ++ hh;
        while (a[q[tt]] >= a[i] && hh <= tt) -- tt;
        q[++ tt] = i;
        cout << a[q[hh]] << ' ';
    }
    //You can also save them all

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

    hh = 1, tt = 0;//init
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