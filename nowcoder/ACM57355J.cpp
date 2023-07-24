#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 MOD = 998244353;

u64 gcd(u64 a, u64 b) {
    return b?gcd(b, a%b):a;
}

/*
template <typename T>
T qpow(T base, u64 exp) {
    T r = base, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r;
        exp >>= 1;
        r = r * r;
    }
    return rst;
}
*/

u64 qpow_mod(u64 base, u64 exp, u64 mod) {
    u64 r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r % mod;
        exp >>= 1;
        r = r * r % mod;
    }
    return rst;
}

u64 inv(u64 x, u64 mod) {
    return qpow_mod(x, mod-2, mod);
}

/*
class Rational {
public:
    u64 numer;
    u64 deno;

    Rational(u64 numer, u64 deno) : numer(numer), deno(deno) {
        u64 k = gcd(numer, deno);
        this->numer /= k;
        this->deno /= k;
    }

    Rational(u64 numer) : numer(numer), deno(1) {}

    Rational() : numer(0), deno(1) {}

    Rational operator*(const Rational& r2) const {
        return Rational(numer * r2.numer, deno * r2.deno);
    }

    Rational& operator*=(const Rational& r2) {
        numer *= r2.numer;
        deno *= r2.deno;
        u64 k = gcd(numer, deno);
        numer = numer % MOD * inv(k, MOD) % MOD;
        deno = deno % MOD * inv(k, MOD) % MOD;
        return *this;
    }

    u64 mod() const {
        return (numer % MOD) * inv(deno % MOD, MOD) % MOD;
    }
};
*/

u64 rational(u64 n, u64 m) {
    return n % MOD * inv(m, MOD) % MOD;
}

u64 solve(int n, int m) {
    int l = (int)floor(log2(n+1));
    int r = (int)floor(log2(n+m));

    if (l == r) return qpow_mod(rational(((u64)1 << l)-1, (u64)1 << l), m, MOD);
    u64 p = 1;
    for (int t = l+1; t < r; t++) {
        p *= qpow_mod(rational(((u64)1<<t)-1, (u64)1<<t), (u64)1<<t, MOD);
        p %= MOD;
    }
    p *= qpow_mod(rational(((u64)1<<l)-1, (u64)1<<l), ((u64)1<<(l+1))-1-n, MOD);
    p %= MOD;
    p *= qpow_mod(rational(((u64)1<<r)-1, (u64)1<<r), n+m-((u64)1<<r)+1, MOD);
    p %= MOD;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;

    return 0;
}