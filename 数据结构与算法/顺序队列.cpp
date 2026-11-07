	//顺序队列				
#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;

struct queue{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}; 

queue* initqueue(){
	queue* q = new queue;
	q->front = 0;
	q->rear = 0; 
	return q;
} 

int isempty(queue* q){
	if(q->front == q->rear){
		return 1;
	}
	else{
		return 0;
	}
}

	//出队 
int dequeue(queue* q,ElemType* e){
	if(q->front == q->rear){
		return 0;
	}
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return 1; 
} 




	//循环队列-入队
int equeue(queue* q,ElemType e){
	
	if((q->rear + 1) % MAXSIZE == q->front){
		cout<<"满了"<<endl; 
		return 0;
	} 
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = e;
	return 1;
} 


int gethead(queue* q,ElemType* e){
	if(q->front == q->rear){
		return 0;
	}
	*e = q->data[q->front];
	return 1;
}


int main(){
	queue* q = initqueue();
	equeue(q,10);
	equeue(q,20);
	equeue(q,30);
	equeue(q,40);
	equeue(q,50);
ElemType de_e;
	// 修正2：先调用dequeue，判断是否成功，再输出元素值
	if(dequeue(q, &de_e)){
		cout << de_e << endl; // 输出第一个出队元素：10
	}
	if(dequeue(q, &de_e)){
		cout << de_e << endl; // 输出第二个出队元素：20
	}
	
	// 获取队头并输出（逻辑正确，保留）
	ElemType e;
	gethead(q,&e);
	

	return 0;
	
}
