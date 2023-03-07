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

unordered_map<int, int> break_num(int val) {
    unordered_map<int, int> res;
    for (int i=0; i < pcnt && primes[i]*primes[i] <= val; i++) {
        int p = primes[i];
        while (val % p == 0) {
            val /= p;
            res[p]++;
        }
    }
    if (val != 1) res[val]++;
    return res;
}

void dfs(unordered_map<int, int>::const_iterator itb, unordered_map<int, int>::const_iterator ite, const function<void(int)>& callback, int mul=1) {
    if (itb == ite) {
        callback(mul);
        return;
    }
    const pair<int, int>& p = *itb;
    itb++;
    int p2 = 1;
    for (int i=0; i<=p.second; i++) {
        dfs(itb, ite, callback, mul*p2);
        p2 *= p.first;
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
    return a/gcd(a, b)*b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    filter_prime();

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (d%c!=0) {
            cout << "0" << endl;
            continue;
        }

        unordered_map<int, int> pb = break_num(d);
        int cnt = 0;
        dfs(pb.cbegin(), pb.cend(), [&cnt, a, b, c, d](int n){
            if (gcd(n, a) == b && lcm(n, c) == d) cnt++;
        });
        cout << cnt << endl;
    }
    return 0;
}