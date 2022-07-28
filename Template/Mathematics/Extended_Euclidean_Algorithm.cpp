#include <bits/stdc++.h>
using namespace std;
#define int long long
// x y will be changed
//return __gcd(a, b);
int __gcd(int a, int b) {
    return b ? __gcd(b, a % b) : a;
}
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
/*
x = x_0 - b / d * k;
y = y_0 + a / d * k;
*/
signed main () {
    return 0;
}