const int N = 1e6 + 10;

// It seems to be a double-ended queue
// Queue
int q[N], hh = 1, tt = 0; // tt - hh + 1 is the number of elements
// Insert x into the queue
void insert(int x) {
    q[++tt] = x;
}
// The back element of the queue
int back() {
    return q[hh];
}
int front() {
    return q[tt];
}
// Pop the front element of the queue
void pop() {
    hh++;
}
// Number of elements
int size() {
    return tt - hh + 1;
}
// Check if the queue is not empty
bool notempty() {
    return hh <= tt;
}
