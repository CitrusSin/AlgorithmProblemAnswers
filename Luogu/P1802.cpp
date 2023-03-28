#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, x;
    cin >> n >> x;

    vector<i64> rewards(n), costs(n);
    int base = 0;
    for (int i=0; i<n; i++) {
        i64 l, w, u;
        cin >> l >> w >> u;
        base += l;
        rewards[i] = w-l;
        costs[i] = u;
    }

    vector<i64> dp(x+1, 0);
    for (i64 i=0; i<n; i++) {
        for (i64 j=x; j>=costs[i]; j--) {
            dp[j] = max(dp[j], dp[j-costs[i]]+rewards[i]);
        }
    }
    i64 total = base + dp[x];
    cout << total*5 << endl;
    return 0;
}