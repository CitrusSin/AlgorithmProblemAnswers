#include <iostream>
#include <cstdint>

using namespace std;

const uint64_t MOD = 1000000007;

int main() {
    uint64_t n;
    cin >> n;
    n--;

    uint64_t ans = 0;
    for (uint64_t i=1; i<=n; i++) {
        ans += (i * (n-i+1) % MOD * (n-i+1) % MOD);
        ans %= MOD;
    }
    cout << ans << '\n';
}