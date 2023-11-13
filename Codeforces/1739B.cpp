#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i=0; i<n; i++) {
        cin >> d[i];
    }

    vector<int> a(n);
    a[0] = d[0];
    for (int i=1; i<n; i++) {
        if (d[i] <= a[i-1] && d[i] != 0) {
            cout << -1 << endl;
            return;
        }
        a[i] = a[i-1] + d[i];
    }

    bool flag = false;
    for (int p : a) {
        if (flag) cout << ' '; else flag = true;
        cout << p;
    }
    cout << endl;
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