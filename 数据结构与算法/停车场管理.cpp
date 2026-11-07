#include <iostream>
#include <cstdlib>
using namespace std;


#define MAXQSIZE 100
#define STACKINCREMENT 10
#define MAX_STACK_SIZE 10  	//静态栈向量大小


typedef int DataType;
typedef int Status;


	//定义栈
typedef struct{
	DataType stack_array[MAX_STACK_SIZE];
	int top;
	int bottom;
}Sqstack;


	//初始化栈 
void initStack(Sqstack *s){
	s->bottom = s->top =0;
}


	//进栈
Status push(Sqstack *s, DataType data){
	if(s->top >= MAX_STACK_SIZE -1){
		cout<< "栈满!"<<endl;
		return 0;
	}
	s->top++;
	s->stack_array[s->top] = data;
	return 1;
} 


	//出栈
Status pop(Sqstack *s, DataType *data){
	if(s->top == 0){
		return 0;
	}
	*data = s->stack_array[s->top];
	s->top--;
	return 1;
} 


	//遍历栈
Status StackTravel(Sqstack *s){
	if(s->top == s->bottom){
		cout<<"停车场为空"<<endl;
		return 0; 
	}
	int prt = s->bottom + 1;
	while(prt <= s->top){
		cout<< s->stack_array[prt];
		if(prt < s->top){
			cout<<",";
		}
		prt++;
	}
	return 1; 
} 


	//顺序表示循环队列  
typedef struct{
	int *base;
	int front;
	int rear;
}SqQueue;


int initQueue(SqQueue *Q){
	Q->base = new int[MAXQSIZE];
	if(!Q->base)
	exit(0);
	Q->front = Q->rear = 0;
	return 1; 
}



	//入队
int  EnQueue(SqQueue *Q, int e){
	if((Q->rear + 1) % MAXQSIZE == Q->front){
		cout<< " 临时区域满！"<<endl; 
		exit(0);	
	}   								
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return 1; 
} 

	//出队
int DeQueue(SqQueue *Q) {
	int e;
	if(Q->front == Q->rear){
		exit(0);
	}
	e = Q->base[Q->front];
	Q->front = (Q->front+1)%MAXQSIZE;
	return e;
}





int main(){
	SqQueue tempArea;
	Sqstack parking;
	initStack(&parking);
	initQueue(&tempArea);
	
	int n;
	cout<< "请输入总车辆数n：";
	cin>> n;
	
		//入栈 
	for(int i = 1; i <= n; i++){
		push(&parking, i);
		 cout << "车辆" << i << "已停入停车场" << endl;
	}
	
	
		int targetCar;
		cout<<"请输入第i辆车出停车场 (1 <= i <= n) : ";
		cin>> targetCar;
		
		
		int car;
		pop(&parking, &car);
		if(car == targetCar){
			cout<< "车辆" << targetCar << "已离开停车场" << endl;
		}
		else{
			cout<<"以下车辆一次进入暂停区域："<<endl;
			cout<< "[";
			cout<<car;
			EnQueue(&tempArea, car);
			
			bool isFirst = false;
		
        while(1){
            pop(&parking, &car);
            if(car == targetCar){
                break;
            }
            EnQueue(&tempArea, car); 
            if(!isFirst){
            	isFirst = true;
			}
			cout<<","<<car;
        }
        cout << "]"<<endl;
        
			
			
			cout<< "车辆" << targetCar << "已离开停车场" << endl;
		
			while(tempArea.front != tempArea.rear){
				int temp = DeQueue(&tempArea);
				push(&parking, temp);
			}
		}
		
	cout << "车辆离开后，停车场中的车辆情况为（由里到外）"<<endl;
	cout<<"["; StackTravel(&parking); cout<<"]";
    delete[] tempArea.base;
	return 0;
		}
