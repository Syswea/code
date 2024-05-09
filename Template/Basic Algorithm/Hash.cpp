#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, p = 1e5 + 7, null = 0x3f3f3f3f;

int h[N], v[N], nxt[N], idx;

int has(int x) {
    return (x % p + p) % p; // Ensure non-negative
}

// Storage structure
// Open addressing
// Linear array length is multiplied
void init() {
    memset(h, 0x3f, sizeof h);
}

int find(int x) {
    int k = has(x); // The modulo p is a prime number 2 ~ 3 times the quantity
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == p) k = 0; // Loop to find an empty slot
    }
    return k;
}

void insert(int x) {
    int k = find(x);
    h[k] = x;
}

bool chk(int x) {
    int k = find(x);
    return h[k] != null;
}

// Separate chaining
// Similar to adjacency list storage
// The chain head is the hash value

void insert(int x) {
    v[idx] = x;
    nxt[idx] = h[has(x)];
    h[has(x)] = idx++;
}
