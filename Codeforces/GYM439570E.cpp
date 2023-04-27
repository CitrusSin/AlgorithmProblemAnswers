#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    int64_t total_profit = 0;
    vector<int> profit_a(n), profit_b(n);
    deque<int> descend_a, descend_b;
    for (int i=n-1; i>=0; i--) {
        while (!descend_a.empty() && a[descend_a.back()] < a[i]) {
            descend_a.pop_back();
        }
        while (!descend_b.empty() && b[descend_b.back()] < b[i]) {
            descend_b.pop_back();
        }
        
        descend_a.push_back(i);
        descend_b.push_back(i);
    }

    cout << total_profit << endl;
    return 0;
}