#include <bits/stdc++.h>
using namespace std;
using db = double;

const db eps = 1e-9;

int sign(db a) {return a < -eps? -1 : a > eps;}

// less -1 , greater 1
int cmp(db a, db b) {return sign(a - b);}

struct P {
    db x, y;
    P() {}
    P(db a, db b): x{a}, y{b}{}

    P operator+ (P p) {return {x + p.x, y + p.y};}
    P operator- (P p) {return {x - p.x, y - p.y};}

    P operator* (db d) {return {x * d, y * d};}
    P operator/ (db d) {return {x / d, y / d};}

    bool operator< (P p) {
        int c = cmp(x, p.x);
        if (c) return c == -1;
        else return cmp(y, p.y) == -1;
    }

    bool operator== (P p) const {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }

    db dot(P p) {return x * p.x + y * p.y;}
    db det(P p) {return x * p.y - y * p.x;}

    db distTo(P p) {return (*this - p).abs()}
    db abs2() {return x * x + y * y;}
    db abs() {return sqrt(abs2());}
};

int main () {
    int c = -1;
    if (c) cout << "minus is true\n";
}