#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

constexpr bool sgn(i64 val) {
    return val<0?true:false;
}

u64 gcd(u64 a, u64 b) {
    return b?gcd(b, a%b):a;
}

u64 lcm(u64 a, u64 b) {
    return a/gcd(a, b)*b;
}

u64 qpow(u64 base, u64 exp, u64 mod) {
    u64 r = 1, b = base % mod;
    while (exp) {
        if (exp & 1) {
            r *= b;
            r %= mod;
        }
        b *= b;
        b %= mod;
        exp >>= 1;
    }
    return r;
}

u64 inv(u64 x, u64 mod) {
    return qpow(x, mod-2, mod);
}

class rational {
private:
    bool neg_sign;
    u64 numer;
    u64 deno;

    static void add_raw(u64 n1, u64 d1, u64 n2, u64 d2, u64& np, u64& dp) {
        dp = lcm(d1, d2);
        n1 *= (dp/d1);
        n2 *= (dp/d2);
        np = n1+n2;

        u64 r = gcd(np, dp);
        np /= r;
        dp /= r;
    }

    static void sub_raw(u64 n1, u64 d1, u64 n2, u64 d2, bool& sgn, u64& np, u64& dp) {
        dp = lcm(d1, d2);
        n1 *= (dp/d1);
        n2 *= (dp/d2);
        np = max(n1, n2) - min(n1, n2);
        sgn = n1<n2;

        u64 r = gcd(np, dp);
        np /= r;
        dp /= r;
    }

    rational& inc_raw(const rational& r2, bool neg) {
        bool type = neg_sign ^ r2.neg_sign ^ neg;
        if (type) {
            bool flip = neg_sign;
            if (flip) {
                sub_raw(r2.numer, r2.deno, numer, deno, flip, numer, deno);
            } else {
                sub_raw(numer, deno, r2.numer, r2.deno, flip, numer, deno);
            }
            neg_sign ^= flip;
        } else {
            add_raw(numer, deno, r2.numer, r2.deno, numer, deno);
        }
        return *this;
    }
public:
    rational(u64 numer, u64 deno) 
        : numer(numer), deno(deno), neg_sign(false)
    {
        simplify();
    }
    rational(i64 numer = 0, i64 deno = 1)
        : numer(abs(numer)), deno(abs(deno)), neg_sign(sgn(numer)^sgn(deno))
    {
        simplify();
    }

    rational(const rational& src) = default;
    rational(rational&& src) = default;
    rational& operator=(const rational& src) = default;
    rational& operator=(rational&& src) = default;
    rational& operator=(i64 numer) {
        *this = rational(numer);
        return *this;
    }

    void simplify() {
        u64 c = gcd(numer, deno);
        numer /= c;
        deno /= c;
    }

    rational& operator+=(const rational& r2) {
        return inc_raw(r2, false);
    }

    rational& operator-=(const rational& r2) {
        return inc_raw(r2, true);
    }

    rational operator+(const rational& r2) const {
        rational rp = *this;
        rp.inc_raw(r2, false);
        return rp;
    }

    rational operator-(const rational& r2) const {
        rational rp = *this;
        rp.inc_raw(r2, true);
        return rp;
    }

    rational& operator*=(const rational& r2) {
        numer *= r2.numer;
        deno *= r2.deno;
        neg_sign ^= r2.neg_sign;
        simplify();
        return *this;
    }

    rational operator*(const rational& r2) const {
        rational rp = *this;
        return rp *= r2;
    }

    rational& operator/=(const rational& r2) {
        if (r2.numer == 0) throw runtime_error("Divided by zero");
        numer *= r2.deno;
        deno *= r2.numer;
        neg_sign ^= r2.neg_sign;
        simplify();
        return *this;
    }

    u64 output_type(u64 mod) const {
        u64 a = numer % mod;
        u64 b = inv(deno % mod, mod);
        return a*b%mod;
    }

    explicit operator string() const {
        stringstream ss;
        if (neg_sign) ss << '-';
        ss << numer;
        if (deno != 1) {
            ss << '/' << deno;
        }
        return ss.str();
    }
};

vector<vector<int>> topsort(const vector<map<int, rational>>& gp) {
    vector<vector<int>> result;

    vector<char> mark(gp.size(), false);
    deque<int> bfsq;
    bfsq.push_back(0);
    mark[0] = true;
    while (!bfsq.empty()) {
        result.emplace_back(bfsq.begin(), bfsq.end());
        size_t s0 = bfsq.size();
        while (s0--) {
            int id = bfsq.front();
            bfsq.pop_front();
            for (const auto& bd : gp[id]) {
                int tgt = bd.first;
                if (!mark[tgt]) {
                    bfsq.push_back(tgt);
                    mark[tgt] = true;
                }
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<rational> probs;
    probs.reserve(n);
    for (int i=0; i<n; i++) {
        u64 p, q;
        cin >> p >> q;
        probs.emplace_back(q-p, q);
    }

    vector<map<int, rational>> gp(n);
    for (int i=0; i<n-1; i++) {
        u64 u, v, a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        gp[u][v] = gp[v][u] = rational(a, b);
    }

    vector<vector<int>> layer = topsort(gp);
    vector<char> vis(n, false);
    
    vector<rational> layer_health_probs(layer.size());
    for (int i=layer.size(); i>=0; i--) {
        rational lp = 1;
        for (int node : layer[i]) {
            vis[node] = true;
            lp *= probs[node];
            for (auto& p : gp[node]) {
                int n2 = p.first;
                if (vis[n2]) continue;
                probs[n2] *= rational(1) - p.second * (rational(1)-probs[node]);
            }
        }
        layer_health_probs[i] = lp;
    }

    rational base_prob = 1, expect = 0;
    for (int t=0; t<layer.size(); t++) {
        expect += rational(t+1) * base_prob * (rational(1)-layer_health_probs[t]);
        base_prob *= layer_health_probs[t];
    }
    expect += rational(layer.size()) * base_prob;

    cout << ((expect.output_type(1000000007)-1)*2) << endl;
    return 0;
}