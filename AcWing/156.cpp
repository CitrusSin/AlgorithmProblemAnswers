#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    queue<int> ascend, descend;
    int min_values[n-k+1], max_values[n-k+1];
    for (int i=0; i<n; i++) {
        if (!ascend.empty() && arr[ascend.back()] > arr[i]) {
            while (!ascend.empty()) ascend.pop();
        }
        ascend.push(i);
        if (ascend.size() > k) ascend.pop();

        if (!descend.empty() && arr[descend.back()] < arr[i]) {
            while (!descend.empty()) descend.pop();
        }
        descend.push(i);
        if (descend.size() > k) descend.pop();

        if (i >= k-1) {
            min_values[i-k+1] = ascend.front();
            max_values[i-k+1] = descend.front();
        }
    }

    int len = n-k+1;
    for (int i=0; i<len; i++) {
        cout << arr[min_values[i]] << " ";
    }
    cout << endl;
    for (int i=0; i<len; i++) {
        cout << arr[max_values[i]] << " ";
    }
    cout << endl;
    return 0;
}