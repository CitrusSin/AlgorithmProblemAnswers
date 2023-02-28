#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (n <= 0) return 1;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> pfsum(n);
    pfsum[0] = arr[0];
    for (int i=1; i<n; i++) {
        pfsum[i] = pfsum[i-1] + arr[i];
    }
    
    deque<int> ascend;
    int max_luck = 1<<31;
    for (int i=0; i<n; i++) {
        if (!ascend.empty() && ascend.front() < i-m) {
            ascend.pop_front();
        }
        int luck = pfsum[i];
        if (!ascend.empty()) {
            if (pfsum[ascend.front()] <= 0 || i >= m) {
                luck -= pfsum[ascend.front()];
            }
        }
        if (luck > max_luck) {
            max_luck = luck;
        }
        while (!ascend.empty() && pfsum[ascend.back()] > pfsum[i]) {
            ascend.pop_back();
        }
        ascend.push_back(i);
    }
    cout << max_luck << endl;
    return 0;
}