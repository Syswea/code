#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char s[N], p[M];
int nxt[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> s + 1;
    cin >> m >> p + 1;

    //calculate prefix array
    //j as the last matched position
    //j + 1 is the character to be matched
    for (int i = 2, j = 0; i <= n; i ++ ) {
        while (j && s[i] != s[j + 1]) j = nxt[j];
        //Recursive solution
        //does not match with i - 1
        //but continues matching with the prefix where it matches
        if (s[i] == s[j + 1]) j ++;
        nxt[i] = j;
    }//Self-matching KMP

    for (int i = 1, j = 0; i <= m; i ++ ) {
        while (j && p[i] != s[j + 1]) j = nxt[j];
        //If there's no match, recursively search
        if (p[i] == s[j + 1]) j ++;
        if (j == n) {//If the end of the string 's' is reached during the search
            cout << i - j << ' ';
            j = nxt[j];
        }
    }
    return 0;
}