#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

#define endl '\n';

u64 gcd(u64 a, u64 b) {
    return b ? gcd(b, a%b) : a;
}

u64 layer_gcd(u64 a, u64 b, u64 &layer) {
    layer = 0;
    if (a < b) {
        swap(a, b);
    }

    if (a % b != 0) {
        u64 p = a/b;
        u64 rst = layer_gcd(b, a%b, layer);
        layer += p+1;
        return rst;
    } else {
        layer = a/b-1;
        return b;
    }
}

// P1 child, P2 parent
bool judge(pair<u64, u64> p1, pair<u64, u64> p2) {
    u64 l1, l2;
    u64 x = layer_gcd(p1.first, p1.second, l1), x2 = layer_gcd(p2.first, p2.second, l2);
    if (x != x2) {
        return false;
    }
    p1.first /= x;
    p1.second /= x;
    p2.first /= x;
    p2.second /= x;

    if (l1 < l2) {
        /*
        swap(l1, l2);
        swap(p1, p2);
        */
       return false;
    }
    // Assert l1 >= l2

    u64 &p1a = p1.first, &p1b = p1.second;
    while (l1 > l2) {
        if (p1a > p1b) {
            u64 dl = p1a / p1b + 1;
            if (dl > l1-l2) break;
            l1 -= dl;
            p1a %= p1b;
        } else if (p1a < p1b) {
            u64 dl = p1b / p1a + 1;
            if (dl > l1-l2) break;
            l1 -= dl;
            p1b %= p1a;
        }
    }
    if (l1 > l2) {
        u64 d = l1-l2;
        if (p1a > p1b) {
            p1a -= d * p1b;
        } else {
            p1b -= d * p1a;
        }
    }
    return p1 == p2;
}

void solve() {
    u64 n, q;
    cin >> n >> q;

    unordered_map<u64, vector<pair<u64, u64>>> mp;
    for (u64 i=0; i<n; i++) {
        pair<u64, u64> p;
        cin >> p.first >> p.second;
        mp[gcd(p.first, p.second)].push_back(p);
    }

    while (q--) {
        pair<u64, u64> sp;
        cin >> sp.first >> sp.second;
        if (!mp.count(gcd(sp.first, sp.second))) {
            cout << 0 << endl;
            continue;
        }
        vector<pair<u64, u64>>& table = mp[gcd(sp.first, sp.second)];
        
        u64 count = 0;
        for (const pair<u64, u64>& p : table) {
            if (p.first < sp.first || p.second < sp.second) {
                continue;
            }
            if (judge(p, sp)) {
                count++;
            }
        }
        cout << count << endl;
    }
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