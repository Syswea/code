#include <bits/stdc++.h>

using namespace std;

int a[123];
int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    nth_element (a, a+4, a + n);
    cout << a[4] << endl;
    return 0;
}