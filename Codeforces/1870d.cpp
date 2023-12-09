#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }

    int k;
    cin >> k;

    deque<int> mntc;
    for (int i=0; i<n; i++) {
        while (!mntc.empty() && c[mntc.back()] >= c[i]) {
            mntc.pop_back();
        }
        mntc.push_back(i);
    }
    
    vector<int> buy_count(mntc.size(), 0);
    buy_count[0] = k/c[mntc[0]];
    int coin_rem = k - buy_count[0] * c[mntc[0]];
    for (int i=1; i<mntc.size(); i++) {
        if (buy_count[i-1] > 0 && coin_rem + c[mntc[i-1]] >= c[mntc[i]]) {
            int step = c[mntc[i]] - c[mntc[i-1]];
            int cnt = min(buy_count[i-1], coin_rem / step);
            buy_count[i-1] -= cnt;
            buy_count[i] += cnt;
            coin_rem = coin_rem - step * cnt;
        }
    }

    vector<int> a(n, 0);
    for (int i=0; i<mntc.size(); i++) {
        a[mntc[i]] = buy_count[i];
    }

    for (int i=n-2; i>=0; i--) {
        a[i] += a[i+1];
    }

    for (int i=0; i<n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

signed main() {
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