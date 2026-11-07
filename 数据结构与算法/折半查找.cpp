#include <iostream>
using namespace std;

typedef int ElemType;

struct sstable{
    ElemType* elem;
    int tablelen;
};

int BS(sstable st, ElemType key){
    int low = 0, high = st.tablelen - 1;
    
    while(low <= high){
        int mid = low + (high - low) / 2;  // 避免整数溢出
        
        if(st.elem[mid] == key){
            return mid;
        }
        else if(st.elem[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    
    // 读取数组大小
    if(!(cin >> n) || n <= 0){
        cout << -1;  
        return 0;
    }
    
    // 动态分配数组
    ElemType* arr = NULL;
    try{
        arr = new ElemType[n];
    }
    catch(const bad_alloc& e){
        cout << -1;  
        return 0;
    }
    
    // 读取数组元素
    for(int i = 0; i < n; i++){
        if(!(cin >> arr[i])){
            delete[] arr; 
            cout << -1;
            return 0;
        }
    }
    
    // 读取要查找的关键字
    ElemType key;
    if(!(cin >> key)){
        delete[] arr;
        cout << -1;
        return 0;
    }
    
    
    sstable st;
    st.elem = arr;
    st.tablelen = n;
    
  
    int result = BS(st, key);
    
    
    cout << result;
    
    
    delete[] arr;
    
    return 0;
}
