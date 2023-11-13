#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+1;
bool vis[N];
int primes[N], pcnt = 0;

void filter_prime() {
    const int n = 1e5;
    for (int i=2; i<n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt; j++) {
            if (1ll*i*primes[j]>n) break;
            vis[i*primes[j]] = true;
            if (i%primes[j]==0) break;
        }
    }
}

int break_num(int val) {
    int res = 1;
    for (int i=0; i < pcnt && primes[i]*primes[i] <= val; i++) {
        int p = primes[i];
        while (val % p == 0) {
            val /= p;
            res += (p-1);
        }
    }
    if (val != 1) res += (val-1);
    return res;
}

int memd[2000001], mlen = 0;
int solve(int n) {
    if (n >= mlen) {
        int r = solve(n-1);
        memd[mlen++] = max(r, break_num(n));
    }
    return memd[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    filter_prime();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}