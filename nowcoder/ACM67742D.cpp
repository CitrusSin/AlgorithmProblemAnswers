#include <bits/stdc++.h>
#include <limits>
#include <locale>
#include <queue>

using namespace std;
using u64 = uint64_t;

u64 phi(u64 x) {
    u64 ans = 1;
    for (u64 i=2; i*i<=x; i++) {
        if (x % i == 0) {
            ans *= i-1;
            x /= i;
            while (x % i == 0) {
                ans *= i;
                x /= i;
            }
        }
    }
    return ans;
}

u64 gcd(u64 a, u64 b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, u64>> cards(m);
    for (int i=0; i<m; i++) {
        cin >> cards[i].first >> cards[i].second;
    }

    int ut = n-k;

    struct pqnode {
        int id;
        u64 dist;
        pqnode(int id, u64 dist) : id(id), dist(dist) {}
        bool operator<(const pqnode& nd2) const {
            return dist > nd2.dist;
        }
    };

    vector<u64> dists(n, numeric_limits<u64>::max());
    vector<char> found(n, false);
    priority_queue<pqnode> notfound;
    notfound.emplace(0, 0);

    while (!notfound.empty()) {
        int id;
        u64 d0;
        do {
            id = notfound.top().id;
            d0 = notfound.top().dist;
            notfound.pop();
        } while (found[id]);

        found[id] = true;
        dists[id] = d0;

        for (auto [offset, weight] : cards) {
            int dest = (id + offset) % n;
            if (found[dest]) continue;

            u64 d1 = d0 + weight;
            if (d1 < dists[dest]) {
                dists[dest] = d1;
                notfound.emplace(dest, d1);
            }
        }
    }

    u64 d = dists[ut];
    if (d == numeric_limits<u64>::max()) {
        cout << -1 << '\n';
    } else {
        cout << d << endl;
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