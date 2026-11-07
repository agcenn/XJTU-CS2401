	//栈实验2
	#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct {
	int x;
	int y;
}elemtype;

struct stack{
	elemtype data[MAXSIZE];
	int top;
};



void initstack(stack* s){
	s->top = -1;
}

int isempty(stack* s){
	if(s->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}


int push(stack* s, elemtype e){
	if(s->top >= MAXSIZE -1){
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return  1;
}

int pop(stack* s,elemtype* x){
	if(s->top == -1){
		return 0;
	}
	*x = s->data[s->top];
	s->top--;
	return 1;
}


int main(){
	stack T;
	initstack(&T);
	elemtype q;
	cout<< "请输入三对坐标: "<<endl;
	for(int i = 0; i < 3; i++){
		cin>> q.x >> q.y;
		push(&T,q);
		cout<< "入栈: "<< q.x<< ","<<q.y<<endl;
	}
	
	cout<< "入栈结束!"<<endl;
	
	while(!isempty(&T)){
		pop(&T,&q);
		cout<< "出栈: "<<q.x<<","<<q.y<<endl;
	}
	
	cout<< "出栈结束!";
	return  0;
} 
