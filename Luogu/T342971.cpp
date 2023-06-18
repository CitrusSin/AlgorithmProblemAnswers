#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 MOD = 1e9+7;

int qpow(int base, unsigned int exp, int mod) {
    i64 r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r % mod;
        r = r * r % mod;
        exp >>= 1;
    }
    return rst;
}

int inv_num(int x, int mod) {
    return qpow(x, mod-2, mod);
}

int combin(int n, int r, int mod) {
    i64 val = 1;
    if (n-r < r) r = n-r;
    for (i64 i=0; i<r; i++) {
        i64 u = n-i, d = r-i;
        val = val * u % mod * inv_num(d, mod) % mod;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int rst = qpow(2, n, MOD) - 1 - combin(n, a, MOD) - combin(n, b, MOD);
    rst %= MOD;
    if (rst < 0) rst += MOD;

    cout << rst << endl;
    return 0;
}