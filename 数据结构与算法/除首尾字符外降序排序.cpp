#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    
    // 若字符串长度≤2，无需处理中间字符，直接输出
    if (len <= 2) {
        cout << s << endl;
        return 0;
    }
    
    // 分离首尾字符与中间部分
    char first = s[0];
    char last = s[len - 1];
    string mid = s.substr(1, len - 2); // 提取除首尾外的中间字符
    
    
    sort(mid.begin(), mid.end(), greater<char>());
    
    
    string result = string(1, first) + mid + last;
    cout << result << endl;
    return 0;
}
