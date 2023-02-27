#include <iostream>
#include <cmath>

using namespace std;
using u64 = uint64_t;

bool isPrime(u64 x) {
    if (x == 0 || x == 1) return false;
    u64 upb = (u64)sqrt(x);
    for (u64 i=2; i<=upb; i++) {
        if (x%i==0) return false;
    }
    return true;
}

u64 gcd(u64 a, u64 b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >>t;
    while (t--) {
        u64 n;
        cin >> n;
        u64 v=n, u=n+1;
        while (!isPrime(v)) v--;
        while (!isPrime(u)) u++;

        u64 ans1 = u*v+2+2*n-2*u-2*v;
        u64 ans2 = 2*v*u;
        u64 div = gcd(ans1, ans2);
        ans1 /= div;
        ans2 /= div;

        cout << ans1 << '/' << ans2 << endl;
    }
    return 0;
}
