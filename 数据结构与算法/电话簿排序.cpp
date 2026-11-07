#include <iostream>
#include <cstring>
using namespace std;

struct contact{
	char name[20];
	int num;
};

contact* p_contact(int n){
	contact* c = new contact[n];
	
	for(int  i = 0; i < n; i++){
		cin>> c[i].name >> c[i].num;
	}
	return c;
}

	//还是选择冒泡来对字母进行排序 
void bubble(contact* c, int n){
	
	for(int i = 0;i < n-1; i++){
		bool flag = false;
		for(int j = 0; j < n-1-i; j++){
			if(strcmp(c[j].name, c[j+1].name) > 0){
				contact temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
				flag = true;
			}
		}
		if(flag == false) break;
	}
}

void prt(contact* c,int n){
	for(int i = 0; i < n; i++){
		cout<< c[i].name << " " <<c[i].num;
		cout<<endl; 
	}
}

int main(){
	int n;
	cin>> n;
	contact* contacts = p_contact(n);
	bubble(contacts,n);
	prt(contacts,n);
	delete[] contacts;
}


