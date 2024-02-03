// n物品分m组
#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 MOD = 1000000007;

u64 qpow(u64 base, u64 exp) {
    u64 r = base % MOD, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r % MOD;
        exp >>= 1;
        r = r * r % MOD;
    }
    return r;
}

u64 inv(u64 x) {
    return qpow(x, MOD-2);
}

u64 fact(u64 x) {
    static vector<u64> fact_data = {1, 1};
    
    while (fact_data.size() >= x) {
        fact_data.push_back(fact_data.size() * fact_data.back() % MOD);
    }
    
    return fact_data[x];
}

int main() {
    u64 n, m;
    cin >> n >> m;
    
    vector<u64> dp(m+1, 0);
    dp[0] = 1;
    for (u64 i=1; i<=n; i++) {
        for (u64 j=m; j>i; j--) {
            dp[j] = (j * dp[j] % MOD + dp[j-1]) % MOD;
        }
        dp[i] = 1;
        for (u64 j=0; j<min(i, m); j++) dp[j] = 0;
    }
    cout << dp[m] << endl;
    return 0;
}