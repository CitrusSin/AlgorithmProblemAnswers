#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 t, m;
    cin >> t >> m;

    vector<u64> val(m), cost(m);

    for (int i=0; i<m; i++) {
        cin >> cost[i] >> val[i];
    }

    vector<u64> dp(t+1, 0);
    for (u64 i=0; i<m; i++) {
        for (u64 j=cost[i]; j<=t; j++) {
            dp[j] = max(dp[j], dp[j-cost[i]]+val[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}