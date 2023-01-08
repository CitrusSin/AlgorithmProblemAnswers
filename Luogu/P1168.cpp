#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    priority_queue<int, vector<int>, greater<int>> a;
    priority_queue<int, vector<int>, less<int>> b;
    a.push(nums[0]);
    cout << nums[0] << endl;
    for (int i=1; i<n; i++) {
        if (nums[i] >= a.top()) {
            a.push(nums[i]);
        } else {
            b.push(nums[i]);
        }
        if (i % 2 == 0) {
            while ((int)a.size() - (int)b.size() > 1) {
                b.push(a.top());
                a.pop();
            }
            while ((int)b.size() - (int)a.size() > 0) {
                a.push(b.top());
                b.pop();
            }
            cout << a.top() << endl;
        }
    }
    return 0;
}