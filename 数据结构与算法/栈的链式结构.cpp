	//Á´Ê½Õ»
#include <iostream>
using namespace std;


#define MAXSIZE  100
typedef int ElemType;

struct stack{
	ElemType data;
	struct stack* next;
};

stack* initstack(){
	stack* s = new stack;
	s->data = 0;
	s->next = NULL;
	return s;
}


int isempty(stack* s){
	if(s->next ==NULL){
		return 0;
	}
	else{
		return 1;
	}
}

int push(stack *s,ElemType e){
	stack* p = new stack;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}


int pop(stack *s,ElemType* e){
	if(s->next == NULL){
		return 0;
	}
	*e = s->next->data;
	stack* q = s->next;
	s->next = q->next;
	delete q;
	return 1;
} 

int gettop(stack* s,ElemType* e){
	if(s->next == NULL){
		return 0;
}
	*e = s->next->data;
}

int main(){
	stack *s =initstack();
	push(s,10);
	push(s,20);
	push(s,30);
	
	ElemType e;
	pop(s,&e);
	cout<< e<< endl;
	
	gettop(s,&e);
	cout<<e;
	return 0;
}
