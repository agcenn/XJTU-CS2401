#include <iostream>
#include <cstring>
using namespace std;

void sort_lowercase_in_place(char arr[]) {
    int n = strlen(arr);
    char low_letters[100];
    int pos[100];
    int cnt = 0;
    
    // 提取所有小写字母及其位置
    for (int i = 0; i < n; i++) {
        if (islower(arr[i])) {
            low_letters[cnt] = arr[i];
            pos[cnt] = i;
            cnt++;
        }

    }
    
    
    // 冒泡 
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = 0; j < cnt - i - 1; j++) {
            if (low_letters[j] > low_letters[j + 1]) {
                char temp = low_letters[j];
                low_letters[j] = low_letters[j + 1];
                low_letters[j + 1] = temp;
            }
        }
    }
    
    	//忽略或删除大写字母 
      for (int i = 0; i < cnt; i++) {
        arr[i] = low_letters[i];
    }
    arr[cnt] = '\0';
}

int main() {
	
	 
    char str[81];
    
    cin >> str;
    sort_lowercase_in_place(str);
    
    cout<< str;
    return 0;
}
