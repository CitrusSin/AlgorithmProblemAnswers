#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

bool in_bound(i64 a, i64 b, i64 c) {
    if (a > b) swap(a, b);
    return a <= c && c <= b;
}

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n), b(n+1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n+1; i++) {
        cin >> b[i];
    }

    i64 min_diff = numeric_limits<i64>::max();
    for (int i=0; i<n; i++) {
        min_diff = min(min_diff, abs(a[i] - b.back()));
        min_diff = min(min_diff, abs(b[i] - b.back()));
    }

    i64 ans = 0;
    bool rem = false;
    for (int i=0; i<n; i++) {
        ans += abs(a[i] - b[i]);
        rem |= in_bound(a[i], b[i], b.back());
    }
    if (!rem) ans += min_diff;
    
    ans++;

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