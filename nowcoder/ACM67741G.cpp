#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    i64 n, m;
    cin >> n >> m;

    vector<pair<i64, i64>> cuts(n);
    for (int i=0; i<n; i++) {
        cin >> cuts[i].first >> cuts[i].second;
    }

    sort(cuts.begin(), cuts.end());
    if (cuts.empty() || cuts[0].first != 0) {
        cuts.insert(cuts.begin(), make_pair(0, 0));
        n++;
    }
    for (int i=1; i<n; i++) {
        cuts[i].second += cuts[i-1].second;
    }

    i64 max_val = 0;
    for (int i=0; i<n; i++) {
        i64 rval = cuts[i].first;
        i64 discount = cuts[i].second;
        i64 pay = rval - discount;
        if (pay <= m) {
            i64 add = rval + (m - pay);
            max_val = max(max_val, add);
        }
    }

    cout << max_val << '\n';
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