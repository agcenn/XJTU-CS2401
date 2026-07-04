#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


class dTree {
public:
    dTree(int a, int b) {
        n = a;
        limit = b;

        parent = new int[n];
        weight = new float[n];
        childCnt = new int[n];
        maxLen = new float[n];
        removed = new bool[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            weight[i] = 0;
            maxLen[i] = 0;
            removed[i] = false;
        }

        // 建树
        for (int i = 0; i < n; i++) {
            cin >> childCnt[i];
            for (int j = 0; j < childCnt[i]; j++) {
                int v;
                float w;
                cin >> v >> w;

                parent[v] = i;
                weight[v] = w;
            }
        }
    }

    ~dTree() {
        delete[] parent;
        delete[] weight;
        delete[] childCnt;
        delete[] maxLen;
        delete[] removed;
    }

    void solution() {
        int ans = 0;

     
        for (int i = n - 1; i >= 0; i--) {

            // 判断是否超限
            if (maxLen[i] > limit) {
                removed[i] = true;
                ans++;
                continue;
            }

            int p = parent[i];

          
            if (p != -1) {
                float candidate = maxLen[i] + weight[i];
                if (candidate > maxLen[p]) {
                    maxLen[p] = candidate;
                }
            }
        }

        cout << ans;
    }

private:
    int n;
    int limit;

    int* parent;
    int* childCnt;
    float* weight;
    float* maxLen;
    bool* removed;
};


int main() {
    int n, d;           //n为顶点个数，d为路径长度
    cin >> n >> d;
    dTree dt(n, d);     //构建与初始化树
    dt.solution();      //通过solution函数输出结果
    return 0;
}
