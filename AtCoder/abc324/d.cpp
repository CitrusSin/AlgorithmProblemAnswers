#include <iostream>
#include <string>
#include <cinttypes>

using u64 = uint64_t;

u64 qpow(u64 base, u64 exp) {
    u64 r = base, rst = 1;
    while (exp) {
        if (exp % 2 == 1) rst *= r;
        r *= r;
        exp /= 2;
    }
    return rst;
}

u64 encode_str(std::string_view val) {
    u64 p = 0;
    for (char c : val) {
        u64 d = c & 0x0f;
        p += 1ULL << (d * 4);
    }
    return p;
}

u64 encode_num(u64 val) {
    u64 p = 0;
    while (val) {
        u64 d = val % 10;
        val /= 10;
        p += 1ULL << (d * 4);
    }
    return p;
}

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    u64 ans = 0;
    u64 enc = encode_str(s);
    u64 uplim = qpow(10, n);
    for (u64 i=0; i*i < uplim; i++) {
        u64 ecr = encode_num(i*i);
        if ((ecr >> 4) == (enc >> 4) && (ecr & 0x0f) <= (enc & 0x0f)) {
            ans++;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}