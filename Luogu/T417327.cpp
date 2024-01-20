#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    i64 n, k;
    cin >> n >> k;

    i64 min_n = k * (k+1) / 2;
    cout << (n >= min_n ? "Yes" : "No") << endl;
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
}