#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 qpow(u64 base, u64 ex, u64 mod) {
    u64 res = 1;
    base %= mod;
    while (ex) {
        if (ex&1) res = (res*base)%mod;
        ex >>= 1;
        base = (base*base)%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 n, p;
    cin >> n >> p;

    cout << 1 << endl;
    vector<u64> pairs(n+1, 0);
    for (int i=2; i<=n; i++) {
        if (pairs[i] == 0) {
            u64 r = qpow(i, p-2, p);
            if (r <= n) {
                pairs[r] = i;
            }
            pairs[i] = r;
        }
        cout << pairs[i] << endl;
    }
    return 0;
}