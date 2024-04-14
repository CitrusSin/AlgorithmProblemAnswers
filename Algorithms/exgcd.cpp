#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int64_t exgcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int64_t x2, y2;
    int64_t ans = exgcd(b, a%b, x2, y2);
    // x2 - L(a/b)*y2 = y
    // x = y2
    x = y2;
    y = x2 - (a/b)*y2;
    return ans;
}

int64_t inv(int64_t a, int64_t m) {
    // ax + my = 1 get x
    int64_t x, y;
    int64_t g = exgcd(a, m, x, y);
    assert(g == 1);

    return (x % m + m) % m;
}

int main() {
    for (;;) {
        cout << "Input a, m: ";
        int64_t a, m;
        cin >> a >> m;

        cout << "Inverse: " << inv(a, m) << '\n';
    }
    return 0;
}