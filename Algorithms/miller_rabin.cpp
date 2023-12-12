#include <atomic>
#include <functional>
#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
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

bool miller_rabin(u64 x, int ti = 50) {
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

bool prime_declare(u64 x) {
    u64 up = sqrt(x) + 100ull;
    for (u64 i = 2; i<=up; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void test() {
    std::atomic_uint64_t idx((1ull << 32) + 1);
    const unsigned int thread_count = std::thread::hardware_concurrency();

    std::vector<std::thread> threads;
    threads.reserve(thread_count);

    std::mutex io_mtx;

    auto error_report = [&io_mtx](u64 x, bool primality) {
        std::lock_guard<std::mutex> lock(io_mtx);
        std::cout << x << " judged wrong, it is a " << (primality?"prime":"composite") << "." << std::endl;
    };

    auto progress_report = [&io_mtx](u64 x) {
        std::lock_guard<std::mutex> lock(io_mtx);
        std::cout << "Progress: " << x << std::endl;
    };

    std::function<void()> task = [&idx, error_report, progress_report]() {
        for ( ; ; ) {
            u64 p = idx++;
            if (p % 1000000 == 0) progress_report(p);
            bool expect = miller_rabin(p);
            if (expect) {
                bool primality = prime_declare(p);
                if (expect != primality) {
                    error_report(p, primality);
                }
            }
        }
    };

    for (unsigned int i=0; i<thread_count; i++) {
        threads.emplace_back(task);
    }
    for (unsigned int i=0; i<thread_count; i++) {
        threads[i].join();
    }
}

int main() {
    test();
    return 0;
}