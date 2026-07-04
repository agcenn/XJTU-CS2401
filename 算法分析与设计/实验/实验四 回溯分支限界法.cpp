#include <iostream>
#include <cmath>
using namespace std;

const int R = 1000;
const int C = 20;

int grid[R][C];
bool ok[C][C];

int assign[C];     
int bestAns[C];    

int curCnt = 0;
int bestCnt = 0;

void build() {
    for (int i = 0; i < C; i++)
        for (int j = 0; j < C; j++)
            ok[i][j] = true;

    for (int i = 0; i < C; i++) {
        for (int j = i + 1; j < C; j++) {
            for (int k = 0; k < R; k++) {
                if (grid[k][i] && grid[k][j]) {
                    ok[i][j] = ok[j][i] = false;
                    break;
                }
            }
        }
    }
}

// 判断是否合法
bool canPut(int col, int tag) {
    for (int i = 0; i < C; i++) {
        if (assign[i] == -tag && !ok[i][col])
            return false;
    }
    return true;
}

// 统计数量
int cnt(int tag, int* arr) {
    int s = 0;
    for (int i = 0; i < C; i++)
        if (arr[i] == tag) s++;
    return s;
}

// 判断集合是否非空
bool validSet() {
    return cnt(1, assign) > 0 && cnt(-1, assign) > 0;
}

// 回溯
void dfs(int idx) {
    if (idx == C) {
        if (!validSet()) return;

        if (curCnt > bestCnt) {
            bestCnt = curCnt;
            for (int i = 0; i < C; i++)
                bestAns[i] = assign[i];
        } else if (curCnt == bestCnt) {
            int a1 = cnt(1, bestAns), b1 = cnt(-1, bestAns);
            int a2 = cnt(1, assign), b2 = cnt(-1, assign);

            if (abs(a1 - b1) > abs(a2 - b2)) {
                for (int i = 0; i < C; i++)
                    bestAns[i] = assign[i];
            }
        }
        return;
    }

    // 放入集合1
    if (canPut(idx, 1)) {
        assign[idx] = 1;
        curCnt++;
        dfs(idx + 1);
        curCnt--;
        assign[idx] = 0;
    }

    // 放入集合2
    if (canPut(idx, -1)) {
        assign[idx] = -1;
        curCnt++;
        dfs(idx + 1);
        curCnt--;
        assign[idx] = 0;
    }

    // 不选
    dfs(idx + 1);
}

// 控制输出
int chooseMainSet() {
    int c1 = cnt(1, bestAns);
    int c2 = cnt(-1, bestAns);

    if (c1 != c2) return (c1 > c2) ? 1 : -1;

    int s1 = 0, s2 = 0;
    for (int i = 0; i < C; i++) {
        if (bestAns[i] == 1) s1 += i;
        if (bestAns[i] == -1) s2 += i;
    }
    return (s1 < s2) ? 1 : -1;
}

int main() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    build();
    dfs(0);

    int t = chooseMainSet();

    for (int i = 0; i < C; i++)
        if (bestAns[i] == t)
            cout << i << " ";
    cout << endl;

    for (int i = 0; i < C; i++)
        if (bestAns[i] == -t)
            cout << i << " ";

    return 0;
}
