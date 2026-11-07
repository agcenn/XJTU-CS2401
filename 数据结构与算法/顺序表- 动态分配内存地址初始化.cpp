	//顺序表 - 动态分配内存地址初始化 

#include <iostream>
#include <cstdlib> //调用malloc 
using namespace std;

#define MAXSIZE 100
typedef int ElemType;



	//动态分配内存地址初始化
typedef struct{
	ElemType *data;
	int length;
}SeqList; 

	//在尾部添加元素 
int appendElem(SeqList *L, ElemType e){
	
	if (L->length >= MAXSIZE){
		cout<< "顺序表已满"<<endl;
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}

	//顺序表遍历 
void listElem(SeqList *L){
	for(int i = 0; i < L->length; i++){
		cout<< L->data[i]; 
			
	if(i != L->length - 1){
		cout<< " ";
	}	
}
	cout<< endl;
}




	//插入数据 
int inserElem(SeqList *L, int pos, ElemType e){
	if(L->length >= MAXSIZE){
		cout<< " 表已经满了"<< endl;
		return 0;
	}
	
	if( pos < 1 || pos > L->length){
		cout<< " 插入位置错误"<< endl;
		return 0; 
	}
	
	if( pos <= L->length){
		for(int i = L->length-1; i >= pos-1; i--){
			L->data[i+1] = L->data[i];
		}
		L->data[pos-1]= e;
		L->length++;
	}
	return 1;
	

}


	//删除数据
int deleteElem(SeqList *L/*顺序表*/, int pos/*删除哪个位置*/, ElemType *e/*保存删除哪那个数据*/){
	if( L->length == 0){
		cout<< "空表"<< endl;
		return 0;
	}
	
	if(pos < 1 || pos > L->length){
		cout<<"删除数据位置有误"<<endl;
		return 0;
	}
	
	*e =  L->data[pos-1];
	if(pos < L->length){
		for(int i = pos; i< L->length; i++){
			L->data[i-1] = L->data[i];
		}
	} 
	L->length--;
	return 1;
} 


	//查找数据位置 
int findElem(SeqList *L, ElemType e){
	if(L->length == 0){
		cout<<" 空列表"<<endl;
		return 0;
	}
	
	for(int i = 0; i < L->length; i++){
		if(L->data[i] == e){
			return i + 1; 
		}
	}
	return 0;
} 



	//动态分配内存地址初始化
SeqList* initList(){
	SeqList *L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length = 0;
	return L; 
 } 

int main(){

	
	//声明一个线性表并初始化
	SeqList *list = initList(); 
	cout<<"初始化成功，目前长度占用"<< list->length<<endl;
	cout<<"目前占用内存"<< sizeof(list->data)<<"字节"<< endl;

	//尾部添加元素 
	appendElem (list, 88); 
	appendElem (list, 45); 
	appendElem (list, 43); 
	appendElem (list, 17); 
	listElem(list);
	
	//插入数据
	inserElem(list, 2, 18);
	listElem(list); 
	
	//删除数据
	ElemType delData;
	deleteElem(list, 2/*要删除的元素*/, &delData);
	cout<< "被删除的数据为："<< delData<<endl;
	listElem(list);
	
	//查找数据位置 
	cout<< "查找的元素在位置："<< findElem(list, 43)<<endl; 
	
	
	//
	return 0; 
}
