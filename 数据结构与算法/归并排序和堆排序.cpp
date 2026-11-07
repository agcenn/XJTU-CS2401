#include <iostream>
using namespace std;

	//归排 - 合并 
void merge(int arr[], int temp[], int left, int mid, int right){
	int l_pos = left;
	int r_pos = mid+1;
	int pos = left;
	
	while(l_pos <= mid && r_pos <= right){
		if(arr[l_pos] <= arr[r_pos]){
			temp[pos++] = arr[l_pos++];
		}
		else{
			temp[pos++] = arr[r_pos++];
		}
	}
	
	while(l_pos <= mid){
		temp[pos++] = arr[l_pos++];
	}
	
	while(r_pos <= right){
		temp[pos++] = arr[r_pos++];
	}
	
	while(left <= right){
		arr[left] = temp[left];
		left++;
	}
}


void MSort(int arr[], int temp[], int left, int right){
	
	if(left < right){
	int mid = (left+right)/2;
	MSort(arr, temp, left, mid);
	MSort(arr,temp, mid+1, right);
	merge(arr, temp, left, mid, right);
	} 
}

	//归排入口 
void MergeSort(int arr[], int n) {
    int *temp = new int[n];  // 创建临时数组
    
    MSort(arr, temp, 0, n - 1);
    
    delete[] temp;
}


void prt(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i];
		if(i != n-1) cout<<" "; 
		cout<< endl;
	} 
	cout<< endl;
}

		//堆排序 
void MaxHeap(int arr[], int n, int i){
	int parent = i;
	int l_child = i*2+1;
	int r_child = i*2+2;
	
	if(l_child<n && arr[parent] > arr[l_child]){
		parent = l_child;
	}
	
	if(r_child<n && arr[parent] > arr[r_child]){
		parent = r_child;
	}
	
	if(parent != i){
		swap(arr[parent],arr[i]);
		MaxHeap(arr,n,parent);
	}
	 
}
		
void HeapSort(int arr[], int n){
	
	int i;
	
	for( i = n/2-1; i>=0; i--){
		MaxHeap(arr, n, i);
	}
	for( i = n-1; i>0; i--){
		swap(arr[i], arr[0]);
		MaxHeap(arr, i, 0);
	}
	
}

int main(){
	int n;
	cin >> n;
	
  int *arr = new int[n];
  int *c_arr = new int[n];  
    

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        c_arr[i] = arr[i]; 
    }
     
    
    MergeSort(arr, n);
    prt(arr,n); 
    
    
  	HeapSort(c_arr,n);
  	prt(c_arr,n);
    
    
    
   
    delete[] arr;
	delete[] c_arr;
	
	return 0;
}
