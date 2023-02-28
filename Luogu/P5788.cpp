#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> ids(n);
    stack<int> dess;
    for (int i=n-1; i>=0; i--) {
        while (!dess.empty() && arr[dess.top()] <= arr[i]) {
            dess.pop();
        }
        if (dess.empty()) {
            ids[i] = -1;
        } else {
            ids[i] = dess.top();
        }
        dess.push(i);
    }

    for (int id : ids) {
        cout << id+1 << " ";
    }
    cout << endl;
    return 0;
}