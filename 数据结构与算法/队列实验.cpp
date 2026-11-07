#include <stdio.h>
#define MAX 100  


typedef struct SqQueue {
    int data[MAX];  
    int front;  
    int rear;    
} SqQueue;


void EnQueue(SqQueue *Q, int x);
int DeQueue(SqQueue *Q);

	//入队
void EnQueue(SqQueue *Q, int x) {
    if ((Q->rear + 1) % MAX == Q->front) {
        printf("队列已满\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MAX;
    Q->data[Q->rear] = x;   
}

	//出队
int DeQueue(SqQueue *Q) {
    if (Q->front == Q->rear) {
        printf("队列已空\n");
        return -9999; 
    }
    Q->front = (Q->front + 1) % MAX;
    return Q->data[Q->front]; 
}

int main() {
    SqQueue queue;
    queue.front = queue.rear = 0;


    EnQueue(&queue, 'A');
    EnQueue(&queue, 'B');
    EnQueue(&queue, 'C');


    printf("出队：%c\n", (char)DeQueue(&queue));

    EnQueue(&queue, 'D');
    EnQueue(&queue, 'E');
    EnQueue(&queue, 'F');


    while (queue.front != queue.rear) {
        printf("出队：%c\n", (char)DeQueue(&queue));
    }

    return 0;
}

