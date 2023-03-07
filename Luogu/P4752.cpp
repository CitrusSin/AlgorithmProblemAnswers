#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const int N = 1e6+10;

bool vis[N];
int primes[N], pcnt = 0;

void filter_prime() {
    int n = 1e6;
    for (int i=2; i<=n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt; j++) {
            if (i*primes[j] > n) break;
            vis[i*primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void prime_break(map<int, int>& res, u64 x) {
    for (int i=0; x>1 && i<pcnt; i++) {
        while (x % primes[i] == 0) {
            x /= primes[i];
            res[primes[i]]++;
        }
    }
    if (x > 1) res[x]++;
}

inline void append_map(map<int, int>& dst, const map<int, int>& tail) {
    for (const pair<int, int>& p : tail) {
        dst[p.first] += p.second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    filter_prime();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        map<int, int> nm, mm;
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            prime_break(nm, p);
        }
        for (int j=0; j<m; j++) {
            int p;
            cin >> p;
            prime_break(mm, p);
        }

        bool flag = true;
        int total = 0;
        for (const pair<int, int>& p : mm) {
            int a = nm[p.first], b = p.second;
            if (b > a) {
                flag = false;
                break;
            } else {
                nm[p.first] -= b;
                total += a-b;
                if (total > 1) {
                    flag = false;
                    break;
                }
            }
        }

        cout << ((flag && total == 1)?"YES":"NO") << endl;
    }
    return 0;
}