#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    uint64_t total = 1;
    for (int x=0, y=0; x<n; x++) {
        while (y < n && a[x] > b[y]) {
            y++;
        }
        if (y-x<=0) {
            total = 0;
            break;
        }
        total *= y-x;
        total %= 1000000007;
    }
    cout << total << endl;
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