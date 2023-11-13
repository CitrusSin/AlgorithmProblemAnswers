#include <bits/stdc++.h>
 
using namespace std;
using u64 = uint64_t;
 
const u64 MOD = 998244353;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    u64 n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;
 
    vector<u64> b(n);
    b[0] = a1;
    u64 ap = (a1*x % m + y) % m;
    for (u64 i=1; i<n; i++) {
        b[i] = ap;
        ap = (ap*x % m + y) % m;
    }
    for (u64 i=1; i<n; i++) {
        b[i] += b[i-1];
        b[i] %= MOD;
    }
    for (u64 i=1; i<n; i++) {
        b[i] += b[i-1];
        b[i] %= MOD;
    }

    for (u64 kp=2; kp<=k; kp++) {
        u64 bkup = b[0];
        b[0] = 0;
        for (u64 i=1; i<n; i++) {
            u64 bkup2 = b[i];
            b[i] = (b[i-1] + bkup) % MOD;
            bkup = bkup2;
        }
    }
 
    u64 xorsum = 0;
    u64 u = 1;
    for (u64 r : b) {
        xorsum ^= u*r;
        u++;
    }
    cout << xorsum << endl;
    return 0;
}