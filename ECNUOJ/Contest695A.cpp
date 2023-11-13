#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> w(n);
    for (int i=0; i<n; i++) {
        cin >> w[i];
    }

    int xs = 0;
    for (int k : w) xs ^= k;
    if (xs != 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << '1';
        for (int i=0; i<n-1; i++) cout << '0';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}