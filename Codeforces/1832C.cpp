#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    auto last_iter = unique(a.begin(), a.end());
    a.erase(last_iter, a.end());

    int count = 0;
    n = a.size();

    for (int i=0; i<n; i++) {
        if (i == 0 || i == n-1) {
            count++;
            continue;
        }
        if (a[i-1] < a[i] && a[i] > a[i+1] || a[i-1] > a[i] && a[i] < a[i+1]) {
            count++;
        }
    }

    cout << count << endl;
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