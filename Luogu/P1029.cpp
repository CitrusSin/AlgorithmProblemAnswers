#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 gcd(u64 a, u64 b) {
    return b?gcd(b, a%b):a;
}

void dfs(
    map<int, int>::const_iterator b,
    map<int, int>::const_iterator e,
    const function<void(u64)>& callback,
    u64 val = 1
) {
    if (b == e) {
        callback(val);
        return;
    }
    pair<int, int> p = *b++;
    u64 product = val;
    for (int t=0; t<=p.second; t++) {
        dfs(b, e, callback, product);
        product *= p.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 x, y;
    cin >> x >> y;

    if (x > y) {
        cout << "0" << endl;
        return 0;
    }

    u64 t = x*y;
    u64 t2 = t;
    map<int, int> prime_decomp;
    for (u64 i=2; t>1 && i*i<=t; i++) {
        while (t%i==0) {
            prime_decomp[i]++;
            t /= i;
        }
    }
    if (t > 1) prime_decomp[t]++;

    u64 cnt = 0;
    dfs(prime_decomp.begin(), prime_decomp.end(), [x, t2, &cnt](u64 n1){
        u64 n2 = t2/n1;
        if (n2 >= n1 && gcd(n1, n2) == x) {
            cnt++;
            if (n2 != n1) cnt++;
        }
    });

    cout << cnt << endl;
    return 0;
}