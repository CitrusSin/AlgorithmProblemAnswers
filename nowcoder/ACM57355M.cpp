#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    i64 d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

i64 solve(i64 a, i64 b, i64 x) {
    if (a < b) swap(a, b);

    i64 p, q;
    i64 k = exgcd(a, b, p, q);
    if (x % k != 0) return -1;

    p *= x/k;
    q *= x/k;
    /*
    while (q < 0) {
        p -= b/k;
        q += a/k;
    }
    */
    if (q < 0) {
        i64 s = -q/(a/k)+1;
        p -= s*b/k;
        q += s*a/k;
    }
    /*
    while (p < 0 || q >= 0) {
        p += b/k;
        q -= a/k;
    }
    */
    if (p <= 0 || q >= 0) {
        i64 s = max(-p/(b/k)+1, q/(a/k)+1);
        p += s*b/k;
        q -= s*a/k;
    }

    i64 p2 = p - b/k, q2 = q + a/k;

    i64 r1 = 2*(abs(p) + abs(q)), r2 = 2*(abs(p2) + abs(q2));
    if (p * q < 0) r1--;
    if (p2 * q2 < 0) r2--;
    if (p <= 0 && q <= 0) return r2;
    if (p2 <= 0 && q2 <= 0) return r1;

    return min(r1, r2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        i64 a, b, x;
        cin >> a >> b >> x;
        cout << solve(a, b, x) << endl;
    }
    return 0;
}