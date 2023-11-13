#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;

template <typename T>
T quick_read() {
    T value = 0;
    char c = cin.get();
    while (c != '-' && (c < '0' || c > '9')) {
        c = cin.get();
    }

    bool neg = false;
    if (c == '-') {
        neg = is_signed<T>::value;
        c = cin.get();
    }

    while (c >= '0' && c <= '9') {
        value *= 10;
        value += c & 0x0f;
        c = cin.get();
    }

    return neg ? -value : value;
}

template <typename T>
void quick_write(T x) {
    if (x == 0) {
        cout << '0';
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    stack<char> qc;
    while (x) {
        int rem = x % 10;
        x /= 10;
        qc.push(rem | 0x30);
    }
    while (!qc.empty()) {
        cout << qc.top();
        qc.pop();
    }
}

template <typename T>
T quick_pow(T base, T exp) {
    T rst = 1, r = base;
    while (exp) {
        if (exp & 1) rst *= r;
        r *= r;
        exp >>= 1;
    }
    return rst;
}

u128 solve(u128 n) {
    u128 r = n/2;
    u128 upper = log((long double)r)/log((long double)5) + 1;
    u128 rst = 0;
    for (u128 i=1; i<=upper; i++) {
        u128 val = quick_pow<u128>(5, i);
        rst += r/val*(r/val*val+val) / 2;
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (u128 i=2; i<=100; i++) {
        quick_write(i);
        cout << ' ';
        quick_write(solve(i));
        cout << endl;
    }
    return 0;
}