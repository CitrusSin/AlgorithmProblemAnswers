#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while (n) {
        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        
        vector<int> left(n), right(n);
        stack<int> ascend;
        for (int i=0; i<n; i++) {
            while (!ascend.empty() && arr[ascend.top()] >= arr[i]) ascend.pop();
            if (ascend.empty()) {
                left[i] = -1;
            } else {
                left[i] = ascend.top();
            }
            ascend.push(i);
        }
        while (!ascend.empty()) ascend.pop();
        for (int i=n-1; i>=0; i--) {
            while (!ascend.empty() && arr[ascend.top()] >= arr[i]) ascend.pop();
            if (ascend.empty()) {
                right[i] = n;
            } else {
                right[i] = ascend.top();
            }
            ascend.push(i);
        }
        
        unsigned long long max_square = 0;
        for (int i=0; i<n; i++) {
            int l = left[i], r = right[i];
            unsigned long long width = r-l-1;
            unsigned long long square = width * arr[i];
            if (square > max_square) max_square = square;
        }
        
        cout << max_square << endl;
        
        cin >> n;
    }
    return 0;
}