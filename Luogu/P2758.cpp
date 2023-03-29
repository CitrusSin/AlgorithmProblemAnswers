#include <bits/stdc++.h>

using namespace std;

int lcs(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) dp[i][0] = i;
    for (int j=1; j<=m; j++) dp[0][j] = j;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }

    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    cout << lcs(a, b) << endl;
    return 0;
}