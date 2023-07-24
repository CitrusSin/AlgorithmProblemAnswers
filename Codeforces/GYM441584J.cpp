#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using c64 = complex<int64_t>;

i64 div_round(i64 a, i64 b) {
    i64 d = a/b, m = a%b;
    if (2*m>=b) {
        d++;
    } else if (2*m <= -b) {
        d--;
    }
    return d;
}

c64 operator/(const c64& a, const c64& b) {
    i64 n = norm(b);
    c64 p2 = a*conj(b);
    return c64(div_round(p2.real(), n), div_round(p2.imag(), n));
}

c64 operator%(const c64& a, const c64& b) {
    return a-(a/b)*b;
}

bool operator==(const c64& a, const c64& b) {
    return a.real() == b.real() && a.imag() == b.imag();
}

c64 gcd(c64 a, c64 b) {
    return norm(b)?gcd(b, a%b):a;
}

void solve() {
    i64 x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    c64 a = c64(x2-x1, y2-y1), b = c64(x3-x1, y3-y1);
    c64 k = gcd(a, b);
    a /= k;
    b /= k;
    cout << "0 0 " << a.real() << ' ' << a.imag() << ' ' << b.real() << ' ' << b.imag() << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}