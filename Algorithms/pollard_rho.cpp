#include <algorithm>
#include <iostream>
#include <functional>
#include <chrono>
#include <random>
#include <utility>

using u64 = std::uint64_t;
using u32 = std::uint32_t;

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

bool miller_rabin(u64 x, int ti = 50) {
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    auto tm = std::chrono::system_clock::now();
    u64 tick = std::chrono::duration_cast<std::chrono::nanoseconds>(tm.time_since_epoch()).count();
    std::uniform_int_distribution<u64> dis(1, x-1);
    std::mt19937_64 mteng(tick);

    std::function<u64()> rd = [&dis, &mteng]() {return dis(mteng);};

    u64 u = x-1, t = 0;
    while (u % 2 == 0) {
        u /= 2;
        t++;
    }

    for (; ti > 0; ti--) {
        u64 a = rd();
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

u64 gcd(u64 a, u64 b) {
    return b ? gcd(b, a%b) : a;
}

u64 pollard_rho(u64 n) {
    auto tm = std::chrono::system_clock::now();
    u64 tick = std::chrono::duration_cast<std::chrono::nanoseconds>(tm.time_since_epoch()).count();
    std::uniform_int_distribution<u64> dis(1, n-1);
    std::mt19937_64 mteng(tick);

    std::function<u64()> rd = [&dis, &mteng]() {return dis(mteng);};

    u64 c;
    std::function<u64(u64)> f = [n, &c](u64 x) {
        return (precise_mul(x, x, n) + c) % n;
    };

    for ( ; ; ) {
        c = rd();

        u64 a = f(0), b = f(f(0));

        u64 t = 0;
        while ((t += a != b), t <= 2) {
            u64 d = gcd(n, a>b?a-b:b-a);
            if (d != 1 && d != n) return d;
            a = f(a);
            b = f(f(b));
        }
    }
}

std::vector<std::pair<u64, u64>> prime_decomp(u64 x) {
    std::vector<u64> ans;

    std::function<void(u64)> func = [&func, &ans](u64 n) {
        if (n == 1) return;
        if (miller_rabin(n)) {
            ans.emplace_back(n);
            return;
        }
        u64 d1 = pollard_rho(n);
        u64 d2 = n / d1;
        func(d1);
        func(d2);
    };

    func(x);

    std::sort(ans.begin(), ans.end());
    std::vector<std::pair<u64, u64>> val;
    for (u64 x : ans) {
        if (!val.empty() && val.back().first == x) {
            val.back().second++;
        } else {
            val.emplace_back(x, 1);
        }
    }

    return val;
}

int main() {
    for (u64 t=14214124; t<8953422546334; t++) {
        std::vector<std::pair<u64, u64>> dec = prime_decomp(t);
        for (auto& p : dec) {
            std::cout << p.first << ',' << p.second << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}