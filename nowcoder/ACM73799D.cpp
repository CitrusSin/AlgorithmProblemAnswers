#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
bool vis[N];
int primes[N], pcnt = 0;

void prime_sieve() {
    for (int i=2; i<N; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt && 1ll * i * primes[pcnt] < N; j++) {
            vis[i * primes[pcnt]] = true;
            if (i % primes[pcnt] == 0) break;
        }
    }
}

void pdcmul(unordered_map<int, int>& ans, int x) {
    for (int i=0; i<pcnt && primes[i] * primes[i] <= x; i++) {
        int cnt = 0;
        while (x % primes[i] == 0) {
            x /= primes[i];
            cnt++;
        }
        if (cnt) {
            ans[primes[i]] += cnt;
        }
    }
    if (x != 1) {
        ans[x]++;
    }
}

void mul2(unordered_map<int, int>& p1, const unordered_map<int, int>& p2) {
    for (const auto& [k, v] : p2) {
        p1[k] += v;
    }
}

int main() {
    prime_sieve();
    int x;
    cin >> x;

    unordered_map<int, int> mp0, mp1;
    for (int i=1; i<=x; i++) {
        pdcmul(mp0, i);
        mul2(mp1, mp0);
    }

    vector<pair<int, int>> factors(mp1.begin(), mp1.end());
    sort(factors.begin(), factors.end());

    cout << "f(" << x << ")=";
    for (int i=0; i<factors.size(); i++) {
        if (i) cout << '*';
        cout << factors[i].first;
        if (factors[i].second > 1) {
            cout << '^' << factors[i].second;
        }
    }
    cout << endl;
}
