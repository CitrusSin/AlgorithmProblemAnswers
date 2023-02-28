#include <iostream>
#include <cstring>

using namespace std;

inline int get_bit(int x, unsigned int digit) {
    return (x >> digit) & 1;
}

inline void set_bit(int &x, unsigned int digit, int val) {
    if (val) {
        x |= (1 << digit);
    } else {
        x &= ~(1 << digit);
    }
}

inline void flip_bit(int &x, unsigned int digit) {
    x ^= (1 << digit);
}

inline int parity(int x, unsigned int start_digit, unsigned int end_digit) {
    int p = 0;
    for (int i=start_digit; i<=end_digit; i++) {
        p ^= get_bit(x, i);
    }
    return p;
}

int bti(const char* str) {
    int result = 0;
    for (const char *ptr = str; *ptr; ptr++) {
        result <<= 1;
        result |= (*ptr)&1;
    }
    return result;
}

bool try_solve(int diff, int n, int &resolution) {
    int begin = get_bit(diff, 0);
    if (begin) { // odd
        int res = 1;
        for (int digit = 1; digit < n-1; digit++) {
            if (parity(res, digit-1, digit+1) != get_bit(diff, digit)) {
                flip_bit(res, digit+1);
            }
        }
        if (parity(res, n-2, n-1) == get_bit(diff, n-1)) {
            resolution = res;
            return true;
        }
        res = 2;
        for (int digit = 1; digit < n-1; digit++) {
            if (parity(res, digit-1, digit+1) != get_bit(diff, digit)) {
                flip_bit(res, digit+1);
            }
        }
        if (parity(res, n-2, n-1) == get_bit(diff, n-1)) {
            resolution = res;
            return true;
        }
    } else {     // even
        int res = 0;
        for (int digit = 1; digit < n-1; digit++) {
            if (parity(res, digit-1, digit+1) != get_bit(diff, digit)) {
                flip_bit(res, digit+1);
            }
        }
        if (parity(res, n-2, n-1) == get_bit(diff, n-1)) {
            resolution = res;
            return true;
        }
        res = 3;
        for (int digit = 1; digit < n-1; digit++) {
            if (parity(res, digit-1, digit+1) != get_bit(diff, digit)) {
                flip_bit(res, digit+1);
            }
        }
        if (parity(res, n-2, n-1) == get_bit(diff, n-1)) {
            resolution = res;
            return true;
        }
    }
    return false;
}

int main() {
    int a, b;
    char buf[31];

    cin >> buf;
    a = bti(buf);
    cin >> buf;
    b = bti(buf);

    int n = strlen(buf);
    int diff = a^b;

    int resolution;
    if (try_solve(diff, n, resolution)) {
        int counter = 0;
        for (int i=0; i<n; i++) {
            counter += get_bit(resolution, i);
        }
        cout << counter << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}