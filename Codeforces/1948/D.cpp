#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    size_t n = s.size();

    vector<vector<uint16_t>> dp(n);
    for (size_t i=0; i<n; i++) dp[i].assign(i+1, 0);
    // dp[i][j] = s[i] == s[j] ? dp[i+1][j+1] + 1 : 0;
    for (size_t i=0; i<n; i++) {
        dp[n-1][i] = s[n-1] == s[i] || s[i] == '?' || s[n-1] == '?';
    }
    for (size_t i=n-2; i<n-1; i--) {
        for (size_t j=0; j<=i; j++) {
            bool crit = s[i] == s[j] || s[i] == '?' || s[j] == '?';
            dp[i][j] = (crit ? dp[i+1][j+1] + 1 : 0);
        }
    }

    int td = 0;
    for (size_t i=0; i<n; i++) {
        for (size_t j=i+1; j<=n-(j-i); j++) {
            if (dp[j][i] >= j-i) {
                td = std::max<int>(td, 2*(j-i));
            }
        }
    }

    cout << td << '\n';
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}