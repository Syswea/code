#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

//根据题目中的要求初始化idx
int head = -1, idx = 1;
struct node {
    int to, next;
}e[N];

void add (int y) {
    e[idx] = {y, head};
    head = idx ++;
}

void del (int k) {
    e[k].next = e[e[k].next].next;
}

void insert (int k, int x) {
    e[idx] = {x, e[k].next};
    e[k].next = idx ++;
}

int m;
int main () {

    cin >> m;
    char ch;
    int x, y;
    while (m -- ) {
        cin >> ch;
        if (ch == 'H') {
            scanf ("%d", &x);
            add (x);
        }
        else if (ch == 'D') {
            scanf ("%d", &x);
            if (x == 0) head = e[head].next;
            else del (x);
        }
        else if (ch == 'I') {
            scanf ("%d%d", &x, &y);
            insert (x, y);
        }
    }

    while (head != -1) {
        cout << e[head].to << ' ';
        head = e[head].next;
    }

    return 0;
}
