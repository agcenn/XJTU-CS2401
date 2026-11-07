#include <iostream>
#include <string>
using namespace std;

typedef struct {
    char* data;  
    int top;     
    int maxSize; 
} CharStack;

// ≥ı ºªØ’ª
void initStack(CharStack& s) {
    s.maxSize = 100; 
    s.data = new char[s.maxSize];
    s.top = -1;       
}

// »Î’ª
void push(CharStack& s, char ch) {
    if (s.top < s.maxSize - 1) { 
        s.data[++s.top] = ch;
    }
}

// ≥ˆ’ª
char pop(CharStack& s) {
    if (s.top != -1) { 
        return s.data[s.top--];
    }
    return '\0';  
}

// ≈–∂œ’ª «∑ÒŒ™ø’
bool isEmpty(CharStack& s) {
    return s.top == -1;
}

int main() {
    string expr;
    getline(cin, expr);  
    
    CharStack stack;
    initStack(stack);
    bool isMatch = true;  
    
    for (char ch : expr) {
        if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            if (isEmpty(stack)) {  
                isMatch = false;
                break;
            }
            pop(stack);
        }
    }
    
    // ◊Ó÷’≈–∂œ£∫’ªø’«“±È¿˙Œﬁ“Ï≥£ °˙ ∆•≈‰£¨∑Ò‘Ú≤ª∆•≈‰
    if (isMatch && isEmpty(stack)) {
        cout << "¿®∫≈∆•≈‰£°" << endl;
    } else {
        cout << "¿®∫≈≤ª∆•≈‰£°" << endl;
    }
    
    delete[] stack.data; 
    return 0;
}
