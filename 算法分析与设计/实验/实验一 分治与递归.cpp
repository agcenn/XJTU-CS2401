#include <iostream> 
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void WeightMedian(int length, vector<int>num, vector<double>weight, int index){
    if (length <= 0) return;

   
    vector< pair<int, double> > arr(length);
    double total_weight = 0;
    for (int i = 0; i < length; ++i) {
       
        arr[i] = make_pair(num[i], weight[i]);
        total_weight += weight[i];
    }

    double w_less_accum = 0;
    double target = total_weight / 2.0;

    while (true) {
        if (arr.size() == 1) {
            cout << arr[0].first << endl;
            return;
        }

        int mid = arr.size() / 2;
        
       
        nth_element(arr.begin(), arr.begin() + mid, arr.end());

        int M = arr[mid].first;

        vector< pair<int, double> > L, E, R;
        double W_L = 0, W_E = 0;

        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i].first < M) {
                L.push_back(arr[i]);
                W_L += arr[i].second;
            } else if (arr[i].first == M) {
                E.push_back(arr[i]);
                W_E += arr[i].second;
            } else {
                R.push_back(arr[i]);
            }
        }

        if (w_less_accum + W_L < target && w_less_accum + W_L + W_E >= target) {
            cout << M << endl;
            return;
        } else if (w_less_accum + W_L >= target) {
            arr = L;
        } else {
            w_less_accum += W_L + W_E;
            arr = R;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    vector<double> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    WeightMedian(n, num, weight, 0);
    return 0;
}
