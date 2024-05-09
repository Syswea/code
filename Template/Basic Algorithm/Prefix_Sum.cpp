#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

//prefix
int *prefix_singel (int *a) {
    int s[N];
    int n = N;
    for (int i = 1; i <= n; i ++ )
        s[i] = s[i - 1] + a[i];
    return s;
}

//[x, y];
int search (int *s, int x, int y) {
    return s[y] - s[x - 1];
}

int **prefix_binary (int **a) {
    int **s;
    int n = N;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    return s;
}

//[x1, x2] * [y1, y2]
int search (int **s, int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][x2 - 1];
}