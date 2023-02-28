#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;

const int mod = 100000;

int fast_pow(int base, int ex) {
    if (ex == 0) return 1;
    if (ex == 1) return base;
    i64 r = fast_pow(base, ex/2);
    if (ex % 2 == 1) {
        return (r*r%mod)*base%mod;
    } else {
        return r*r%mod;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int t = n*m;
    int res = fast_pow(2, t);
    res--;
    if (res < 0) res += mod;
    cout << res << endl;
    return 0;
}