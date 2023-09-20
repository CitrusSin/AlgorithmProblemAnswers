#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x < k-1) {
        cout << -1 << '\n';
        return;
    }
    if (x == k) x--;
    if (n >= k) {
        int sr = k*(k-1)/2 + (n-k)*x;
        cout << sr << '\n';
    } else {
        cout << -1 << '\n';
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