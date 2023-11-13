#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 sqrt_int(u64 n) {
    u64 x=1;
    for (;;) {
        u64 x2 = (x+n/x)/2;
        if (x != x2) {
            x = x2;
        } else {
            return x2;
        }
    }
}

u64 sum(u64 n) {
    if (n==0) return 0;
    u64 x = (sqrt_int(8*n+1)-1)/2;
    u64 nfloor = x*(x+1)/2;
    
    u64 s = (x*(x+1)*(2*x+1)/6+x*(x+1)/2)/2;
    s += (n-nfloor)*(n-nfloor+1)/2;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        u64 l, r;
        cin >> l >> r;
        cout << (sum(r)-sum(l-1)) << endl;
    }
    return 0;
}