#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    i64 a, b, c;
    cin >> a >> b >> c;

    int copy_limit = (int)log2(c) + 1;
    i64 ans = numeric_limits<i64>::max();
    for (int copy = 0; copy <= copy_limit; copy++) {
        i64 person = 1ll << copy;
        i64 ti = a * copy + b * (c / person + (c % person > 0));
        ans = min(ans, ti);
    }

    cout << ans << '\n';
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