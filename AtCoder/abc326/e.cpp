#include <iostream>
#include <vector>

using i64 = int64_t;
const i64 MOD = 998244353;

i64 qpow(i64 base, i64 exp, i64 mod) {
    i64 r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = (rst * r) % mod;
        exp >>= 1;
        r = r * r % mod;
    }
    return rst;
}

i64 inv(i64 x, i64 mod) {
    return qpow(x, mod-2, mod);
}

i64 qpow(i64 base, i64 exp) {
    return qpow(base, exp, MOD);
}

i64 inv(i64 x) {
    return inv(x, MOD);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    i64 n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i=0; i<n; i++) {
        std::cin >> a[i];
        a[i] %= MOD;
    }

    std::vector<i64> dp(n);
    dp[0] = a[0];
    for (i64 i=1; i<n; i++) {
        i64 r = inv(i+1);
        i64 s = i*r%MOD;
        dp[i] = r*a[i]%MOD + s*((s*dp[i-1]%MOD + r*((dp[i-1]+a[i])%MOD)%MOD)%MOD)%MOD;
        dp[i] %= MOD;
    }
    std::cout << dp[n-1] << std::endl;
    return 0;
}