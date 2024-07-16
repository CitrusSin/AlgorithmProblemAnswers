#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 N = 10000001;
bool vis[N];
int primes[N], pcnt = 0;
int ft[N];

void prime_sieve() {
    for (int i=2; i<N; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt && 1ll * i * primes[j] < N; j++) {
            vis[i*primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int f(int n) {
    if (n == 1) return 0;
    
    if (!vis[n]) return 1;
    if (n % 2 == 0 || !vis[n-2]) return 2;
    return 3;
}


void solve() {
    int n;
    cin >> n;

    cout << ft[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prime_sieve();
    ft[0] = 0;
    for (int i=1; i<N; i++) {
        ft[i] = ft[i-1] + f(i);
    }

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}