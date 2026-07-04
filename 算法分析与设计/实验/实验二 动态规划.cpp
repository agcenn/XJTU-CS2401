#include <iostream> 
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


void MinCost(int L, int n, int *p) {
    // 排序切割点（p[0]=0 和 p[n+1]=L 已固定，只排序中间的切割点）
    sort(p + 1, p + n + 1);
    
    // 初始化dp数组，大小为(n+2)x(n+2)，因为切割点包括0和L
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    
    // 遍历区间长度l（从2开始，因为至少需要两个点才能形成区间）
    for (int l = 2; l <= n + 1; ++l) {
        for (int i = 0; i <= n + 1 - l; ++i) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            // 枚举中间切割点k
            for (int k = i + 1; k < j; ++k) {
                int cost = dp[i][k] + dp[k][j] + (p[j] - p[i]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    // 输出最小代价
    cout << dp[0][n + 1] << endl;
}


int main() {

    // 后台自动给出测试代码放在这里，无需同学编写

    int L, n;
    cin >> L >> n;
    int *p;
    p = new int[n + 2];
    p[0] = 0;
    p[n + 1] = L;
    for (int i = 1; i < n + 1; i++) {
        cin >> p[i];
    }

    MinCost(L, n, p); //调用函数输出一个切割最小的代价和，结果通过cout输出，均为int类型

    return 0;

}
