#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 qpow(i64 base, i64 exp, i64 mod) {
    i64 rst = 1, r = base % mod;
    while (exp) {
        if (exp & 1) rst = rst * r % mod;
        r = r * r % mod;
        exp >>= 1;
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n, m, q;
    cin >> n >> m >> q;

    vector<vector<i64>> combinatorics(n+1);
    for (i64 u = 0; u <= n; u++) combinatorics[u].assign(u+1, 0);
    combinatorics[0][0] = 1;
    for (i64 u = 1; u <= n; u++) {
        combinatorics[u][0] = combinatorics[u][u] = 1;
        for (i64 v = 1; v < u; v++) {
            combinatorics[u][v] = (combinatorics[u-1][v-1] + combinatorics[u-1][v]) % q;
        }
    }
    
    i64 ans = 0;
    for (i64 i=1; i<=n; i++) {
        ans += combinatorics[n][i] * qpow((qpow(2, n, q) - qpow(2, n-i, q)) % q + q, m-1, q);
        ans %= q;
    }
    cout << ans << '\n';
    return 0;
}
