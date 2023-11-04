#include <iostream>
#include <cinttypes>

using i64 = std::int64_t;

i64 qpow(i64 base, i64 exp) {
    i64 r = base, rst = 1;
    while (exp) {
        if (exp & 1) rst *= r;
        r *= r;
        exp >>= 1;
    }
    return rst;
}

int main() {
    i64 b;
    std::cin >> b;

    for (i64 i=1; qpow(i, i) <= b; i++) {
        if (qpow(i, i) == b) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}