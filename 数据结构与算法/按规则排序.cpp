#include <iostream>
using namespace std;

int main(){
	int n,a[100],res[100]={0};
	cin>> n;
	
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	
	int copy[100];
	for(int i = 0; i < n; i++) copy[i]= a[i];
	
	
		//я║ее 
	for(int  i = 0; i < n-1; i++){
		int min_i= i;
		for(int j = i+1; j < n; j++){
			if(copy[min_i] > copy[j]){
					min_i= j;
			}
		}
			if(min_i != i){
				int temp = copy[i];
				copy[i] = copy[min_i];
				copy[min_i] = temp;
			}		
				
		}
		int min = copy[0];
		int mid = copy[n/2];
		int max = copy[n-1];
		
		res[0]= min;
		res[n/2] = max;
		res[n-1] = mid;
		
		for(int i = 0; i < n; i++){
			cout<< res[i];
			if(i != n-1) cout<< " ";
		}
		
		
		return 0; 
	}
	

