#include <bits/stdc++.h>

using namespace std;

vector<char> vis;
vector<uint64_t> primes;
uint64_t sieve_upper = 1;

void prime_sieve(uint64_t n) {
    if (vis.size() < n+1) vis.resize(n+1);
    for (uint64_t i=sieve_upper+1; i<=n; i++) {
        if (!vis[i]) primes.push_back(i);
        size_t psize = primes.size();
        for (size_t j=0; j<psize; j++) {
            uint64_t p = primes[j];
            if (i*p > n) break;
            vis[i*p] = true;
            if (i%p == 0) break;
        }
    }
    sieve_upper = n;
}

int main() {
    cout << "Input x: ";
    int64_t a;
    cin >> a;

    cout << "Input minimum mod: ";
    int64_t mmod;
    cin >> mmod;

    prime_sieve(mmod*2);
    for (auto it = lower_bound(primes.begin(), primes.end(), mmod); it != primes.end(); it++) {
        uint64_t p = *it;
        bool result = false;
        uint64_t res = 0;
        for (uint64_t n=2; n<p/2+1; n++) {
            if ((n*n)%p == a) {
                result = true;
                res = n;
                break;
            }
        }
        if (result) {
            cout << "Mod " << p << ": " << res << " " << p-res << endl;
        } else {
            cout << "Mod " << p << ": None" << endl;
        }
    }
    return 0;
}