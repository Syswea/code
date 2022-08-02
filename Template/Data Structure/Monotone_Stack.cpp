#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int sta[N], top = 0;
int main () {
    cin >> n;
    sta[++ top] = -1;

    int k;
    while (n -- ) {
        cin >> k;
        while (k <= sta[top] && top) -- top;//栈内有元素才能 pop
        cout << sta[top] << ' ';
        sta[++ top] = k;
    }
    return 0;
}