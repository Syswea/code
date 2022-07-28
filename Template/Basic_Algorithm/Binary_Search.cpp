#include <bits/stdc++.h>

using namespace std;

bool check (int k);

//[l, mid],[mid + 1, r];
int bsearch_l (int l, int r) {

    while (l < r) {
        int mid = l + r >> 1;
        if (check (mid)) r = mid;
        else l = mid + 1;
    }

    return l;
}

//[l,mid - 1],[mid, r];
int bsearch_r (int l, int r) {

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check (mid)) l = mid;
        else r = mid - 1;
    }

    return r;
}

int main () {
    return 0;
}