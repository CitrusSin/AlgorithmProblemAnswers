#include <iostream>

using namespace std;
using i64 = int64_t;

bool check_interval(i64 pos, i64 lm, i64 rm, i64 mod) {
    pos = (pos % mod + mod) % mod;
    return rm >= lm ? pos >= lm && pos <= rm : pos >= 0 && pos <= rm || pos >= lm && pos < mod;
}

int main() {
    i64 a, m, l, r;
    cin >> a >> m >> l >> r;
    
    i64 lm = (l % m + m) % m, rm = (r % m + m) % m;
    
    i64 ans = abs(l-r) / m + check_interval(a, lm, rm, m);
    cout << ans << endl;
    return 0;
}