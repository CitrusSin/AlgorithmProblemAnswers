#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    deque<int> descend;
    for (int i=0; i<n; i++) {
        if (!descend.empty() && descend.front() <= i-k) {
            descend.pop_front();
        }
        while (!descend.empty() && arr[descend.back()] < arr[i]) {
            descend.pop_back();
        }
        descend.push_back(i);
        if (i >= k-1) {
            cout << arr[descend.front()] << endl;
        }
    }
    return 0;
}