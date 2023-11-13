#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 f(u64 n) {
    u64 res = 0;
    for (u64 j=1; j<=n; j++) {
        u64 a = n/j;
        u64 b = a-1;
        if (a%2==0) a/=2; else b/=2;
        u64 p = a*b;
        res += p*j+(n%j+1)*(n/j);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        u64 n;
        cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}