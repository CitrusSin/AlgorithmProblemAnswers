#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 MOD = 1e9+7;

void exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

i64 inv(i64 a) {
    // ax+MODy=1
    i64 x, y;
    exgcd(a, MOD, x, y);
    while (x<0) x+=MOD;
    x %= MOD;
    return x;
}

i64 fact(i64 x) {
    static vector<i64> arr;
    if (arr.size() == 0) {
        arr.push_back(1);
    }
    for (i64 i=arr.size(); i<=x; i++) {
        arr.push_back((arr[i-1]*(i%MOD))%MOD);
    }
    return arr[x];
}

i64 comb(i64 n, i64 m) {
    // Cnm = n!/m!(n-m)!
    i64 q = fact(n);
    i64 deno = (fact(m)*fact(n-m))%MOD;
    return (q * inv(deno)) % MOD;
}

i64 cross_permutation(i64 l) {
    // cp_n = (n-1)(cp_n-1 + cp_n-2)
    static vector<i64> arr;
    if (arr.size() == 0) {
        arr.push_back(1);
        arr.push_back(0);
        arr.push_back(1);
    }
    for (i64 i=arr.size(); i<=l; i++) {
        arr.push_back((i-1)%MOD*((arr[i-1]+arr[i-2])%MOD)%MOD);
    }
    return arr[l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        i64 result = (comb(n, m) * cross_permutation(n-m))%MOD;
        cout << result << endl;
    }
    return 0;
}