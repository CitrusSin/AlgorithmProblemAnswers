#include <iostream>
#include <vector>

using namespace std;
typedef long long int i64;

const int N = 1200;

int primes[N], pcnt = 0;
bool vis[N];

void euler_sieve() {
    int n = 1200;
    for (int i=2; i<n; i++) {
        if (!vis[i]) primes[pcnt++] = i;
        for (int j=0; j<pcnt && i*primes[j]<n; j++) {
            vis[i*primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int phi(int x) {
    int r = x, ph = x;
    for (int id=0; id<pcnt && primes[id]*primes[id]<=r; id++) {
        int p = primes[id];
        if (r % p == 0) ph = ph / p * (p-1);
        while (r % p == 0) r /= p;
    }
    if (r > 1) ph = ph / r * (r-1);
    return ph;
}

i64 phi_sum(int x) {
    static vector<i64> psums;
    if (psums.size() == 0) {
        psums.push_back(0);
        psums.push_back(phi(1));
    }
    for (int i=psums.size(); i<=x; i++) {
        psums.push_back(psums[i-1] + phi(i));
    }
    return psums[x];
}

i64 solve(int n) {
    // 1+2*(phi(1)+phi(2)+phi(3)+...+phi(n))
    return 1+2*phi_sum(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    euler_sieve();

    int c;
    cin >> c;

    for (int i=1; i<=c; i++) {
        int n;
        cin >> n;
        cout << i << ' ' << n << ' ' << solve(n) << endl;
    }
    return 0;
}