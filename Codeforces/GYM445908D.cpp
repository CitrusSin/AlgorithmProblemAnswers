#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n, m;
    cin >> n >> m;
    int64_t base = 0;
    vector<int64_t> b(n);
    for (int i=0; i<n; i++) {
        int64_t p, q;
        cin >> p >> q;
        b[i] = q-p;
        base += p;
    }

    int64_t mxn = min(n, m-n);
    if (m % 2 == 1) {
        if (m-n == n-1) {
            mxn = n;
        }
    }
    int64_t inc = 0;
    sort(b.begin(), b.end());
    int64_t cnt = 0;
    vector<int64_t> recs;
    recs.push_back(base);
    for (int64_t i=n-1; i>=0; i--) {
        if (cnt >= mxn) break;
        base += b[i];
        cnt++;
        if (cnt != n-1) recs.push_back(base);
    }

    int64_t result = 0;
    for (int64_t v : recs) result = max(result, v);
    cout << result << endl;
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