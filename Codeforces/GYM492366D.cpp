#include <functional>
#include <iostream>
#include <chrono>
#include <ostream>
#include <random>
#include <sstream>
#include <string_view>
#include <vector>

using u64 = std::uint64_t;
using u32 = std::uint32_t;

std::random_device rdev;
std::mt19937_64 eng(rdev());

constexpr u64 precise_mul(u64 a, u64 b, u64 mod) {
    __int128_t v = a;
    v *= b;
    v %= mod;
    return v;
}

u64 qpow(u64 base, u64 exp, u64 mod) {
    u64 r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = precise_mul(rst, r, mod);
        r = precise_mul(r, r, mod);
        exp >>= 1;
    }
    return rst;
}

bool miller_rabin(u64 x, int ti = 70) {
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    std::uniform_int_distribution<u64> rd(1, x-1);

    u64 u = x-1, t = 0;
    while (u % 2 == 0) {
        u /= 2;
        t++;
    }

    for (; ti > 0; ti--) {
        u64 a = rd(eng);
        u64 d = qpow(a, u, x);
        if (d == 1) continue;
        for (u64 i=0; i<t; i++) {
            if (d == x-1) break;
            d = precise_mul(d, d, x);
            if (d == 1) return false;
        }
        if (d != 1 && d != x-1) return false;
    }
    return true;
}

int main() {
    for (u64 i=2; i<=1e18; i++) {
        if (miller_rabin(i)) {
            std::stringstream ss;
            ss << i;
            std::string str = ss.str();
            std::string_view sv(str);
            
            bool test = true;
            for (size_t i=0; test && i<sv.size(); i++) {
                for (size_t j=1; test && i+j <= sv.size(); j++) {
                    std::string_view sv2 = sv.substr(i, j);

                    u64 val;
                    std::stringstream cvt;
                    cvt << sv2;
                    cvt >> val;

                    if (!miller_rabin(val)) test = false;
                }
            }

            if (test) {
                std::cout << i << std::endl;
            }
        }
    }
    std::cout << std::endl;
    return 0;
}