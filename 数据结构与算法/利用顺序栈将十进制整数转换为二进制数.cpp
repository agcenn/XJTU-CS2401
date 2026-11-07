#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int top;
}Stack;

// 初始化 - 置空栈
void initStack(Stack *s){
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s){
    return s->top == -1; 
}

// 进栈
int push(Stack *s, ElemType e){
    if(s->top >= MAXSIZE - 1){
        cout << "栈已满，无法入栈" << endl;
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 出栈
int pop(Stack *s, ElemType *e){
    if(isEmpty(s)){
        return 0; 
    }
    *e = s->data[s->top];
    s->top--;
    return 1; 
}

int GetLength(Stack *s) {
    return s->top + 1;
}

int main() {
    int n;
    cin >> n;

    Stack stack;
    initStack(&stack);

    // 处理0的特殊情况
    if (n == 0) {
        push(&stack, 0);
    } else {
        // 除2取余法入栈
        while (n != 0) {
            int remainder = n % 2;
            remainder = (remainder + 2) % 2; 
            push(&stack, remainder);
            n = n / 2;
        }
    }

    // 输出栈长度
    cout << "表长：" << GetLength(&stack) << endl;

    // 出栈并输出二进制数
    cout << "二进制：";
    int e;
    while (pop(&stack, &e)) {
        cout << e;
    }
    cout << endl;

    return 0;
}
