#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 MOD = 998244353;

u64 slowpow(u64 base, u64 exp) {
    u64 rst = 1;
    for (u64 i=0; i<exp; i++) rst *= base;
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 n;
    cin >> n;

    vector<u64> arr(n);
    for (u64 i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<u64> psum(n);
    psum[0] = arr[0] % MOD;
    for (u64 i=1; i<n; i++) {
        psum[i] = psum[i-1] + arr[i] % MOD;
        psum[i] %= MOD;
    }

    u64 total = 0;
    for (u64 i=n-1; i>0; i--) {
        u64 val = arr[i];
        u64 dig = slowpow(10, (int)floor(log10(val)) + 1) % MOD;
        val %= MOD;
        total += (psum[i-1] * dig % MOD) + (val * i % MOD) % MOD;
        total %= MOD;
    }

    cout << total << '\n';
    return 0;
}