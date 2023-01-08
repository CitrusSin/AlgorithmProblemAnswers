#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
     
    int cost[n], value[n];
     
    for (int i=0; i<n; i++) {
        cin >> cost[i] >> value[i];
    }
     
    int dp[m+1];
    memset(dp, 0, (m+1)*sizeof(int));
    for (int i=0; i<n; i++) {
        for (int j=m; j>=cost[i]; j--) {
            dp[j] = max(dp[j], dp[j-cost[i]]+value[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}