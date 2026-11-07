	//队列-链式结构
#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElemType;

typedef struct QueueNode{
	ElemType data;
	struct QueueNode *next;
}QueueNode;


typedef struct{
	QueueNode *front;
	QueueNode *rear;
}Queue; 

	//初化
Queue* initQueue(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	QueueNode *node = (QueueNode*)malloc(sizeof(Queue));
	node->data = 0;
	node->next = NULL;
	q->front = node;
	q->rear = node;
	return q;
} 

	//判断队列是否为空
int isEmpty(Queue *q){
	if(q->front == q->rear){
		return 1; 
	}
	else{
		return 0;
	}
} 

	//入队
void equeue(Queue *q, ElemType e){
	QueueNode *node = (QueueNode*)malloc(sizeof(Queue));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;
} 

	//出队
int dequeue(Queue *q, ElemType *e){
	if(isEmpty(q)){
		cout<<"空的"<<endl;
		return 0;
	}
	
	QueueNode *node = q->front->next;
	*e = node->data;
	q->front->next = node->next;
	if(q->rear == node){
		q->rear = q->front;
	}
	free(node);
	return 1;
} 


	//获取队头元素
ElemType getFront(Queue *q){
	if(isEmpty(q)){
		cout<<"空的"<<endl;
		return 0;
	}
	return q->front->next->data;
} 


int main(){
	Queue *q = initQueue();
	equeue(q, 'A');
	equeue(q, 'B');
	equeue(q, 'C');
	equeue(q, 'D');
	equeue(q, 'E');
	equeue(q, 'F');
	ElemType e;
	dequeue(q,&e);
	cout<<e<<endl;
	dequeue(q,&e);
	cout<<e<<endl;
		dequeue(q,&e);
	cout<<e<<endl;
		dequeue(q,&e);
	cout<<e<<endl;
		dequeue(q,&e);
	cout<<e<<endl;
		dequeue(q,&e);
	cout<<e<<endl;
	return 0;
} 


