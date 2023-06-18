#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int primes[N], pcnt = 0;
bool vis[N];

void prime_sieve() {
    for (int i=2; i<N; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt && i * primes[j] < N; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

template <typename Iter>
int gcd(Iter itb, Iter ite) {
    int val = 0;
    for (Iter it = itb; it != ite; it++) {
        val = gcd(val, *it);
    }
    return val;
}

unordered_map<int, int> pdc(int x) {
    unordered_map<int, int> rst;
    for (int i=0; i < pcnt && primes[i] * primes[i] <= x; i++) {
        while (x % primes[i] == 0) {
            rst[primes[i]]++;
            x /= primes[i];
        }
    }
    if (x != 1) {
        rst[x]++;
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prime_sieve();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int k = gcd(a.begin(), a.end());
    vector<unordered_map<int, int>> maps(n);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        maps[i] = pdc(a[i] / k);
        cnt += maps[i][2] + maps[i][3];
        if (maps[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;
    return 0;
}