#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, m;
    cin >> t >> m;
    vector<int> cost(m), val(m);
    for (int i=0; i<m; i++) {
        cin >> cost[i] >> val[i];
    }

    vector<int> dp(t+1, 0);
    for (int i=0; i<m; i++) {
        for (int j=t; j>=cost[i]; j--) {
            dp[j] = max(dp[j], dp[j-cost[i]]+val[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}