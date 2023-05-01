#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using u32 = uint32_t;

const u64 MOD = 998705927;
const u64 SQRT3 = 317872642;
const u64 NEG_SQRT3 = 680833285;
const u64 INV2 = 499352964;

const u64 P = SQRT3 * INV2 % MOD;

struct vec {
    u32 x;
    u32 y;

    constexpr vec() : x(0), y(0) {}
    constexpr vec(u32 x, u32 y) : x(x%MOD), y(y%MOD) {}

    constexpr vec operator+(const vec& v2) const {
        return vec(x+v2.x, y+v2.y);
    }

    constexpr vec operator-() const {
        return vec(MOD-x, MOD-y);
    }

    constexpr vec operator-(const vec& v2) const {
        return vec(MOD+x-v2.x, MOD+y-v2.y);
    }

    constexpr u64 hash() const {
        return (u64(x) << 32) | y;
    }
};

const vec R1(1, 0), R2(MOD-INV2, P), R3(MOD-INV2, MOD-P);

u64 solve(const string& s) {
    size_t n = s.size();

    unordered_map<u64, u64> count;

    vec p(0, 0);
    u64 total_count = 0;
    for (size_t i=0; i<n; i++) {
        char c = s[i];
        switch (c) {
        case 'X':
            p = p + R1;
            break;
        case 'T':
            p = p + R2;
            break;
        case 'U':
            p = p + R3;
            break;
        }
        total_count += count[p.hash()];
        count[p.hash()]++;
        if (p.x == 0 && p.y == 0) {
            total_count++;
        }
    }
    return total_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}