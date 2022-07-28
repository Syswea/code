const int N = 1e6 + 10;

//栈
int sta[N], top = 0;//栈底是1,top既是栈顶,也是栈中元素的个数
//入栈x
void insert (int x) {
    sta[++ top] = x;
}
//找出top元素
int top_element () {
    return sta[top];
}
//删除栈顶元素
void pop () {
    -- top;
}
//元素个数
int size() {
    return top;
}
