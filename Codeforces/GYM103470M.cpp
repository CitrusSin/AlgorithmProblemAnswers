#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int64_t sum = 0;
    for (int i=0; i<n/2; i++) {
        sum -= a[i];
    }
    for (int i=n/2; i<n; i++) {
        sum += a[i];
    }
    cout << sum << '\n';
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