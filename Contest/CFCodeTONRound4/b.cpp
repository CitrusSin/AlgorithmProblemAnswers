#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%2==0) {
            cout << "-1" << endl;
            continue;
        }
        n >>= 1;
        stack<int> ops;
        while (n>1) {
            ops.push((n%2)+1);
            n >>= 1;
        }
        ops.push(2);
        cout << ops.size() << endl;
        bool f = false;
        while (!ops.empty()) {
            if (f) cout << " ";
            cout << ops.top();
            ops.pop();
            f = true;
        }
        cout << endl;
    }
    return 0;
}