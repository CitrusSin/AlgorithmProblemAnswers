#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    bool result = true;

    i64 n, m;
    cin >> n >> m;

    map<i64, i64> mp;
    for (int i=0; i<m; i++) {
        i64 a, b;
        cin >> a >> b;
        if (!mp.count(a)) {
            mp[a] = b;
        } else if (mp[a] != b) {
            result = false;
        }
    }

    i64 idx = 0, cnt = 0;
    for (const auto& [i2, c2] : mp) {
        bool ok = c2-cnt == i2-idx || c2 < i2 - idx;
        if (!ok) {
            result = false;
        } 
        cnt = c2;
        idx = i2;
    }

    cout << (result ? "Yes" : "No") << endl;
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