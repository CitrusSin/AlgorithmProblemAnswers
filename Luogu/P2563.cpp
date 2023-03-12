#include <bits/stdc++.h>

using namespace std;

const int N = 201;
bool vis[N];
int primes[N], pcnt = 0;

void prime_sieve() {
    int n = 200;
    for (int i=2; i<=n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt && i*primes[j]<=n; j++) {
            vis[i*primes[j]] = true;
            if (i%primes[j] == 0) break;
        }
    }
}

int dp[N][N];
int solve(int sp, int n) {
    if (primes[sp] > n) return 0;
    if (dp[sp][n] != 0) return dp[sp][n];

    if (primes[sp] == n) {
        dp[sp][n] = 1;
        return 1;
    }

    int cnt = 0;
    int n2 = n;
    while (sp < pcnt && n2 >= primes[sp]) {
        cnt += solve(sp+1, n2);
        n2 -= primes[sp];
    }
    if (n2 == 0) cnt++;
    dp[sp][n] = cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prime_sieve();

    int n;
    while (cin >> n) {
        cout << solve(0, n) << endl;
    }
    return 0;
}