#include <bits/stdc++.h>

using namespace std;

uint64_t qpow(uint64_t base, uint64_t exp, uint64_t mod) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base%mod;
    }

    uint64_t r = qpow(base, exp/2, mod);
    r *= r;
    r %= mod;
    if (exp % 2) {
        r *= base%mod;
        r %= mod;
    }
    return r;
}

uint64_t pow(uint64_t n, uint64_t m, uint64_t p) {
    uint64_t power_cnt = 2;
    uint64_t value = (n*n)%m;
    while (value != n) {
        power_cnt++;
        value *= n%m;
        value %= m;
    }
    power_cnt--;

    return qpow(n, p%power_cnt, m);
}

int main() {
    uint64_t n, m, p;
    cin >> n >> m >> p;
    cout << pow(n, m, p) << endl;
    return 0;
}