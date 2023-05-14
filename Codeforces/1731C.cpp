#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

bool square_number(u64 x) {
    u64 p = floor(sqrt(x));
    return p*p==x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<n; i++) {
        a[i] ^= a[i-1];
    }
    // a[l]^a[r]=sq => sq^a[r] = a[l]
    vector<int> mpc(2*n, 0);
    u64 odcnt = 0;
    for (int i=0; i<n; i++) {
        for (int sq=0; sq*sq < 2*n; sq++) {
            int d = (sq*sq)^a[i];
            if (d < 2*n) {
                odcnt += mpc[d];
            }
        }
        if (square_number(a[i])) odcnt++;
        mpc[a[i]]++;
    }
    u64 cnt = u64(n)*u64(n+1)/2 - odcnt;
    cout << cnt << endl;
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