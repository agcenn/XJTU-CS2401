	//√∞≈›≈≈–Ú-—°‘Ò≈≈–Ú£®ƒÊ–Ú£©
#include <iostream>
using namespace std;


void BubbleSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		bool flag= false;
		for(int j = 0; j < n-1-i;j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = true;
			}
		}
		if(flag == false) break;
	}
}  

void select(int a[], int n) {
	for(int i = 0; i < n-1; i++){
		int max = i;
		for(int j = i+1; j < n; j++){
			if(a[j] > a[max]){
				max = j;
			}
		}
		int temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	} 
}

void insersort(int a[],int n){
	for(int i = 1; i < n; i++){
		int key = a[i];
		int j = i-1;
		while(j>=0 && a[j] < key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
} 



int main(){
	int arr[10];
	int b[10];
	int s[10];
	int in[10];
	
	for(int i = 0; i < 10; i++){
		cin >> arr[i]; 
		b[i] = arr[i];
		s[i] = arr[i];
		in[i] = arr[i];
	}
	
	BubbleSort(b,10);
	for(int i = 0;i < 10; i++){
		cout<<b[i] << " ";
	}
	cout<< endl;
	
	select(s,10);
	for(int i = 0; i < 10; i++){
		cout<< s[i] << " ";
	}
	cout<<endl; 
	
	insersort(in, 10);
	for(int i = 0; i < 10; i++){
		cout<<in[i] << " " ;
	}
	
	return 0;
}
