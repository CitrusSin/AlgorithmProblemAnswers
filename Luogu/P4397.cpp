#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const int N = 1e5+1;

bool vis[N];
int primes[N], pcnt = 0;

int ans[N], acnt = 0;

void filter_primes() {
    int n = 1e5;
    for (int i=2; i<=n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt; j++) {
            if (i*primes[j] > n) break;
            vis[i*primes[j]] = true;
            if (i%primes[j]==0) break;
        }
    }
}

bool is_prime(int val) {
    for (int i=0; primes[i]<=val/primes[i]; i++) {
        if (val%primes[i]==0) return false;
    }
    return true;
}

void dfs(int s, int p, int mul) {
    if (s == 1) {
        ans[acnt++] = mul;
        return;
    }
    if (s > primes[pcnt-1] && is_prime(s-1)) {
        ans[acnt++] = mul * (s-1);
    }
    for (; p<pcnt; p++) {
        int v = primes[p]+1, pw = primes[p];
        if (v > s) break;
        while (v <= s) {
            if (s%v==0) {
                int ns = s/v;
                dfs(ns, p+1, mul*pw);
            }
            v = v*primes[p]+1;
            pw *= primes[p];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    filter_primes();

    int s;
    while (cin >> s) {
        acnt = 0;
        dfs(s, 0, 1);

        sort(ans, ans+acnt);
        cout << acnt << endl;
        for (int i=0; i<acnt; i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        if (acnt) cout << endl;
    }

    return 0;
}
