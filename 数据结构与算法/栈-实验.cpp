	//栈 实验
#include <iostream>
#include <cstdlib>  //调用malloc 
using namespace std;


#define MAXSIZE  100
typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int top;
}Stack;


	//初始化 
void initStack(Stack *s){
	s->top = -1;
}


	//判断 
int isEmpty(Stack *s){
	if(s->top == -1){
		cout<< "空的"<<endl;
		return 1;
	}
	else{
		return 0;
	}
}


	//进栈 
int push(Stack *s, ElemType e){
	if(s->top >= MAXSIZE -1){
		cout<< "满了"<< endl;
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1; 
} 

	//出栈
ElemType pop(Stack *s, ElemType *e){
	if(s->top == -1){
		cout<< "空的"<< endl;
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
} 


	//获取栈顶元素
int getTop(Stack *s, ElemType *e){
	if(s->top == -1){
		cout<< "空的"<< endl;
		return 0; 
	}
	*e = s->data[s->top];
	return 1;
} 


 


int main(){
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	ElemType e;
	pop(&s,&e);
	cout<< e<<endl;
	getTop(&s,&e);
	cout<< e << endl;
	return 0;
} 
