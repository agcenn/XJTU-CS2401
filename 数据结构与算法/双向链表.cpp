	//双向链表
#include <iostream>
#include <cstdlib> //调用mallc=oc 
using namespace std;

	//链表存储结构
typedef int ElemType;


typedef struct node{
	ElemType data;
	struct node *next, *prev;
}Node; 



	//初始化
Node* initList(){
	Node *head =  (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	return head;
} 


	//头插法
int inserHead(Node* L, ElemType e){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = L;
	p->next = L->next;
	if(L->next != NULL){
		L->next->prev = p;
	}
	L->next = p;
	return 1;
} 


	//遍历
void listNode(Node* L){
	Node *p = L->next;
	while(p != NULL){
		cout<< p->data << " ";
		p = p->next;
	}
	cout<<endl;
} 


	//获取尾节点
Node* get_tail(Node *L){
	Node *p = L;
	while(p->next != NULL){
		p = p->next;
	}
	return p;
} 

	//尾插法
Node* inserTail(Node *tail, ElemType e){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = tail;
	tail->next = p;
	p->next = NULL;
	return p;
} 


	//在指定位置插入数据
int insertNode(Node *L, int pos, ElemType e){
		//用来保存插入位置的前驱节点
	 Node *p = L;
	 int i = 0;
	 
	 	//遍历链表找到插入位置的前驱节点
		 while(i < pos-1){
		 	p = p->next;
		 	i++;
		 	if( p == NULL){
		 		return 0;
			 }
		 } 
		 
		 //插入新节点
		 Node *q = (Node*)malloc(sizeof(Node));
		 q->data = e;
		 q->next = p->next;
		 p->next ->prev = q;
		 p->next = q;
		 return 1; 
}


	//删除
int deleteNode(Node *L, int pos){
		//要删除节点的前驱 
	Node *p = L;
	int i = 0;
		//遍历链表，找到要删除节点的前驱
	while(i < pos-1){
		p = p->next;
		i++;
		if(p == NULL){
			return 0;
		}
	} 
	if(p->next == NULL){
		cout<<"要删除的的位置错误"<<endl;
		return 0;
	}
	//q想要删除的节点
	 Node *q = p->next;
	 p->next = q->next;
	 q->next->prev = p;
	 //释放要删除节点的内存空间
	 free(q);
	 return 1; 
}


	//获取链表长度
int listLength(Node *L){
	Node *p = L;
	int len = 0;
	while(p != NULL){
		p = p->next;
		len++;
	}
	return len;
} 


	//释放链表
void freeList(Node *L){
	Node *p  = L->next;
	Node *q;
	
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
} 

int main(){
	
	//初始化 
	Node *list = initList();
	
	 
	Node *tail = get_tail(list);
/*	
	//遍历 
	 inserHead(list, 10);
	 inserHead(list, 20);
	inserHead(list, 30);
	listNode(list);
*/



		//遍历 
	tail = inserTail(tail, 10);
	tail = inserTail(tail, 20);
	tail = inserTail(tail, 30);
	listNode(list);	
	

	//插入 
	insertNode(list, 2, 15);
	listNode(list);

	//删除
	 deleteNode(list, 2);
	 listNode(list);
	
	
	//获取链表长度 
	cout<<"链表长度为："<<listLength(list)<<endl;
	
	//释放链表 
	freeList(list);
	cout<<"释放后链表长度为："<<listLength(list)<<endl;


	return 0;
} 
