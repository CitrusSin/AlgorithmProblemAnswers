#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using i64 = int64_t;

u64 gcd(u64 a, u64 b) {
    return b?gcd(b, a%b):a;
}

u64 lcm(u64 a, u64 b) {
    return a/gcd(a, b)*b;
}

template <typename Container>
u64 lcm(const Container& cc) {
    u64 r = 1;
    for (u64 p : cc) {
        r = lcm(r, p);
    }
    return r;
}

vector<pair<u64, u64>> prime_break(u64 n) {
    vector<pair<u64, u64>> rs;
    for (u64 d=2; d*d<=n; d++) {
        if (n % d == 0) {
            u64 cnt = 0;
            while (n % d == 0) {
                n /= d;
                cnt++;
            }
            rs.emplace_back(d, cnt);
        }
    }
    if (n > 1) {
        rs.emplace_back(n, 1);
    }
    return rs;
}

template <typename Iter>
bool enumerate_factor(Iter b, Iter e, const function<bool(u64)>& cb, u64 base = 1) {
    if (b == e) {
        return cb(base);
    }

    const pair<u64, u64>& pp = *b;
    u64 p = pp.first, exp = pp.second;

    u64 pt = base;
    Iter next_iter = b;
    next_iter++;
    for (u64 rexp = 0; rexp <= exp; rexp++) {
        bool do_next = enumerate_factor(next_iter, e, cb, pt);
        if (!do_next) {
            return false;
        }
        pt *= p;
    }
    return true;
}

void exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (b) {
        exgcd(b, a%b, x, y);
    } else {
        x = 1;
        y = 0;
        return;
    }
    int t = x;
    x = y;
    y = t-(a/b)*y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<u64> lens(n);
    for (int i=0; i<n; i++) {
        cin >> lens[i];
    }

    u64 t = lcm(lens);
    t *= 2;
    
    vector<pair<u64, u64>> tpbv = prime_break(t);

    i64 result = numeric_limits<i64>::max();
    enumerate_factor(tpbv.rbegin(), tpbv.rend(), [t, &result](i64 a) {
        i64 b = t/a;
        if (a > b) swap(a, b);
        if (a != 1 && b != 1 && gcd(a, b) == 1) {
            i64 x, y;
            exgcd(a, b, x, y);
            if (x < 0) {
                x *= -a;
                y *= b;
            } else {
                x *= a;
                y *= -b;
            }
            result = min(result, min(x, y));
        }
        return true;
    });
    cout << result << endl;
    return 0;
}