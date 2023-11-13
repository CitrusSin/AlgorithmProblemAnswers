#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

uint64_t qpow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t b = base % mod, r = 1;
    while (exp) {
        if (exp & 1) {
            r *= b;
            r %= mod;
        }
        b *= b;
        b %= mod;
        exp >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //2^((n-1)%1e9+6) mod (1e9+7)
    uint64_t rst = 0;
    char c;
    while (c = cin.get(), c >= '0' && c <= '9') {
        rst *= 10;
        rst %= MOD-1;
        rst += c & 0x0f;
        rst %= MOD-1;
    }
    if (rst == 0) {
        rst = MOD-2;
    } else {
        rst--;
    }

    cout << qpow(2, rst, MOD) << endl;
    return 0;
}