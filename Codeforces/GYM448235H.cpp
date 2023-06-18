#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    int n, k;
    cin >> n >> k;

    int mx = n + (k/2);
    int mi = n - ((k-1)/2);

    if (mx > 2*n) mx = 2*n;
    if (k > 2*n) mi = 0;

    cout << mi << ' ' << mx << endl;
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