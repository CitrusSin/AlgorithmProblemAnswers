#include <bits/stdc++.h>

using namespace std;

uint32_t euler_func(uint32_t x) {
    uint32_t r = x;
    vector<uint32_t> decomp;
    for (uint32_t p=2; uint64_t(p)*p<=uint64_t(r); p++) {
        if (r % p == 0) {
            decomp.push_back(p);
        }
        while (r % p == 0) {
            r /= p;
        }
    }
    if (r > 1) decomp.push_back(r);

    for (uint32_t p : decomp) {
        x = x / p * (p-1);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    uint32_t n;
    cin >> n;

    uint64_t result = 0;
    for (uint32_t d=1; uint64_t(d)*d<=uint64_t(n); d++) {
        if (n % d == 0) {
            uint32_t d2 = n/d;
            result += d2 * euler_func(d);
            if (d2 != d) result += d * euler_func(d2);
        }
    }

    cout << result << endl;
    return 0;
}