#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

int primes[N], pcnt=0;
bool vis[N];

void euler_sieve(int n) {
    for (int i=2; i<=n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt && i*primes[j]<=n; j++) {
            vis[i*primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int first_factor(int x) {
    if (!vis[x]) return x;
    for (int i=0; i<pcnt; i++) {
        if (x % primes[i] == 0) return primes[i];
    }
    return x;
}

void solve() {
    int n, m;
    cin >> n >> m;

    if (n > 1 && first_factor(n) <= m) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    euler_sieve(1000000);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}