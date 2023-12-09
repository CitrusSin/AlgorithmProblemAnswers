#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    i64 p, m;
    cin >> p >> m;

    i64 kc = m / p;
    i64 kcu = (m-2)/p+1;
    for (i64 k = kc; k <= kcu; k++) {
        i64 g = (p-1) ^ (k*p+1);
        if (g <= m) kc++;
    }

    cout << kc << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}