const int N = 1e6 + 10;

// Stack
int sta[N], top = 0;
// The bottom of the stack is 1, top is both the top of the stack and the number of elements in the stack
// Push x onto the stack
void insert(int x) {
    sta[++top] = x;
}
// Find the top element
int top_element() {
    return sta[top];
}
// Pop the top element of the stack
void pop() {
    --top;
}
// Number of elements
int size() {
    return top;
}
