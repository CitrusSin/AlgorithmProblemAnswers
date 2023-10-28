#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    deque<int> deq;
    vector<int> rst(n, 0);
    for (int i=n-1; i>=0; i--) {
        while (!deq.empty() && deq.back() <= arr[i]) {
            deq.pop_back();
        }
        if (deq.size() >= 2) rst[i] = deq[deq.size()-2];
        deq.push_back(arr[i]);
    }

    for (int i : rst) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}