#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const int N = 1e6+10, MOD = 1e9+7;
bool vis[N];
int primes[N], pcnt = 0;

void filter_primes() {
    int n = 1e6;
    for (int i=2; i<=n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt; j++) {
            if (i*primes[j] > n) break;
            vis[i*primes[j]] = true;
            if (i%primes[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    filter_primes();

    u64 n;
    cin >> n;
    vector<int> nums(pcnt, 0);

    for (int i=0; i<pcnt; i++) {
        u64 p = primes[i];
        while (p <= n) {
            nums[i] += n/p;
            p *= primes[i];
        }
    }

    u64 res = 1;
    for (int i=0; i<pcnt; i++) {
        res *= (2*nums[i]+1);
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}