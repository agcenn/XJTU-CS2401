/*#include<iostream>
#define MAX 100
using namespace std;

	//定义元素 
typedef struct point{
	int x;
	int y;
}ElemType;

	
typedef struct Sqstack{
	ElemType *data;
	int top;
	int stacksize;
}Sqstack;

		//初化 
void initStack(Sqstack &s, int size){
	if(size > 0 ){
		s.stacksize = size;
		s.data = new ElemType[size];
		s.top = -1;
	}
	else{
		cout<<"堆栈初始化长度错误"<<endl;
	}
}

		//入栈
void push(Sqstack &s, ElemType x){
	if(s.top < s.stacksize - 1){
		s.top++;
		s.data[s.top] = x;
	}
	else{
		cout<<"栈满"<<endl;
	}
} 


		//出栈
void pop(Sqstack &s, ElemType &e){
	if(s.top > - 1){
		s.data[s.top] = e;
		s.top--;
	}
	else{
		cout<<"栈空"<<endl;
	}
} 


int main(){
	Sqstack T;
	ElemType s;
	initStack(T,20);
	cout<< "请输入三对空坐标"<<endl;
	for( int i=0; i<3; i++){
		cin>>s.x>>s.y;
		push(T,s);
		cout<<"入栈: "<<s.x<<","<<s.y<<endl;
	}	
	
	cout<<"入栈结束！"<<endl;
	
	//弹栈并输出直到栈空
	while(T.top >= 0){
		pop(T,s);
		cout<<"出栈: "<<s.x<<","<<s.y<<endl; 
	}
	
	cout<<"出栈结束！"<<endl;
	
	delete[] T.data;
	return 0;
}*/


#include <iostream>
using namespace std;

// 定义平面点结构体（数据元素）
typedef struct point {
    int x;  // x坐标
    int y;  // y坐标
} ElemType;

// 顺序栈结构体定义
typedef struct Sqstack {
    ElemType* data;    // 存储元素的数组指针
    int top;           // 栈顶指针（存储栈顶元素下标）
    int stacksize;     // 栈的最大容量（元素个数）
} SqStack;

// 1. 初始化栈
void InitStack(SqStack& s, int size) {
    if (size > 0) {          // 验证容量合法性
        s.stacksize = size;  // 设置栈最大容量
        s.top = -1;          // 空栈时top为-1
        s.data = new ElemType[size];  // 动态分配内存
    } else {
        cout << "堆栈初始化长度错误" << endl;
    }
}

// 2. 入栈操作
void Push(SqStack& s, ElemType x) {
    if (s.top < s.stacksize - 1) {  // 栈未满（top最大值为stacksize-1）
        s.top++;                    // 栈顶指针上移
        s.data[s.top] = x;          // 新元素存入栈顶
    } else {
        cout << "栈满" << endl;
    }
}

// 3. 出栈操作
void Pop(SqStack& s, ElemType& e) {
    if (s.top > -1) {  // 栈非空（top >= 0）
        e = s.data[s.top];  // 取出栈顶元素
        s.top--;            // 栈顶指针下移
    } else {
        cout << "栈空" << endl;
    }
}

int main() {
    SqStack T;         // 定义栈对象
    ElemType s;        // 用于接收输入和出栈的点

    InitStack(T, 20);  // 初始化栈，容量为20
    cout << "请输入三对坐标：\n";

    // 入栈3个点
    for (int i = 0; i < 3; i++) {
        cin >> s.x >> s.y;  // 输入坐标
        Push(T, s);         // 入栈
        cout << "入栈：" << s.x << "," << s.y << endl;
    }
    cout << "入栈结束！\n";

    // 出栈所有元素（修正原代码中栈对象的引用错误）
    while (T.top >= 0) {  // 循环条件：栈非空（栈顶指针T.top >= 0）
        Pop(T, s);        // 出栈
        cout << "出栈：" << s.x << "," << s.y << endl;
    }
    cout << "出栈结束！\n";

    // 释放动态分配的内存（避免内存泄漏）
    delete[] T.data;
    return 0;
}





