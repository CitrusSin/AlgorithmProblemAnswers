#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >>n;

    vector<int> h(n);
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    stack<int> dec;
    vector<int> look(n);
    for (int i=n-1; i>=0; i--) {
        while (!dec.empty() && h[dec.top()] <= h[i]) {
            dec.pop();
        }
        look[i] = dec.empty()?-1:dec.top();
        dec.push(i);
    }

    for (int i=0; i<n; i++) {
        cout << (look[i]+1) << endl;
    }
    return 0;
}