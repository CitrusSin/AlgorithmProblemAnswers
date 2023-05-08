#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

void enumerate_k(int k, int digit, const function<void(int)>& cb, int last = 0) {
    if (digit == 0) {
        if (k == 0) {
            cb(last);
        }
        return;
    }
    if (k < digit) {
        enumerate_k(k, digit-1, cb, last << 1);
    }
    if (k > 0) {
        enumerate_k(k-1, digit-1, cb, (last << 1)+1);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int dp[n+1][64];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=n; i++) {
        dp[i][arr[i-1]]++;
        dp[i][arr[i-1]] %= MOD;
        for (int j=0; j<=63; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            dp[i][arr[i-1]&j] += dp[i-1][j];
            dp[i][arr[i-1]&j] %= MOD;
        }
    }
    int total = 0;
    enumerate_k(k, 6, [n, &dp, &total](int p) {
        total += dp[n][p];
        total %= MOD;
    });
    cout << total << endl;
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