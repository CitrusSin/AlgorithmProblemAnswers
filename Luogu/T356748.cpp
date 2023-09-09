#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 qpow(i64 base, uint64_t exp) {
    i64 rst = 1, r = base;
    while (exp) {
        if (exp & 1) rst *= r;
        exp >>= 1;
        r *= r;
    }
    return rst;
}

namespace sp {
    i64 n;
    i64 d;
    i64 k;

    i64 f1(i64 kr, i64 l) {
        return n - (qpow(kr, l+1)-1) / (kr-1);
    }

    i64 f2(i64 kr, i64 l) {
        return d - (l*qpow(kr, l+1) - ((qpow(kr, l+1)-kr) / (kr-1))) / (kr-1);
    }
}

void setv(i64 n, i64 d, i64 k) {
    sp::n = n;
    sp::d = d;
    sp::k = k;
}

void solve() {
    i64 n, d, k;
    cin >> n >> d >> k;

    if (n == 1 && d == 0) {
        cout << "YES" << endl << endl;
        return;
    }

    if (n-1 < k) {
        cout << "NO" << endl;
        return;
    }

    setv(n, d, k);

    i64 lr = log(n*(k-1)+1) / log(k), ll = 1;
    while (ll < lr) {
        i64 l = (lr + ll) / 2;
        bool test = false;
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}