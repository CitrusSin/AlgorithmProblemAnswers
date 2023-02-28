#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    int dp[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i] == b[j]) {
                int val = 1;
                if (i > 0 && j > 0) {
                    val += dp[i-1][j-1];
                }
                dp[i][j] = val;
            } else {
                int val = 0;
                if (i > 0) {
                    val = max(val, dp[i-1][j]);
                }
                if (j > 0) {
                    val = max(val, dp[i][j-1]);
                }
                dp[i][j] = val;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
    return 0;
}