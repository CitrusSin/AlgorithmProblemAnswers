#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 MOD = 998244353;

u64 qpow(u64 base, u64 exp, u64 mod) {
    u64 b = base % mod, r = 1;
    while (exp) {
        if (exp&1) {
            r *= b;
            r %= mod;
        }
        exp >>= 1;
        b *= b;
        b %= mod;
    }
    return r;
}

int main() {
    u64 k;
    cin >> k;

    u64 n = qpow(2, k-1, MOD);
    cout << n << endl;
    return 0;
}