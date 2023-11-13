#include <bits/stdc++.h>

#define endl '\n';

using namespace std;
using i64 = int64_t;

void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n);
    for (i64 i=0; i<n; i++) {
        cin >> a[i];
    }

    if (a[0] != 1) {
        cout << 1 << endl;
        return;
    }

    i64 p = 1, idx = 0, kt = 0;
    while (idx < n && p <= a.back()) {
        i64 df = a[idx]-idx-1;
        while (df >= p && p <= a.back()) {
            p += idx;
            kt++;
            if (kt == k) {
                cout << p << endl;
                return;
            }
        }
        idx++;
    }
    i64 fdf = a[n-1]-n;
    while (fdf >= p) {
        p += n-1;
        kt++;
        if (kt == k) {
            cout << p << endl;
            return;
        }
    }
    cout << (p + (k-kt)*n) << endl;
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