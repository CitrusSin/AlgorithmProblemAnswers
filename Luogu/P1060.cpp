#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> costs(m), values(m);
    for (int i=0; i<m; i++) {
        int v, p;
        std::cin >> v >> p;
        costs[i] = v;
        values[i] = v*p;
    }

    std::vector<int> dp(n+1, 0);
    for (int i=0; i<m; i++) {
        for (int j=n; j>=costs[i]; j--) {
            dp[j] = std::max(dp[j], dp[j-costs[i]]+values[i]);
        }
    }

    std::cout << dp[n] << std::endl;
    return 0;
}