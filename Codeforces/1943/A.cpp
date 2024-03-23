#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        mp[p]++;
    }

    int u = 0;
    if (mp.count(0) && mp[0] == 1) {
        u = 1;
        while (mp[u]>=2) u++;
        cout << u << '\n';
    } else {
        while (mp[u]>=2) u++;
        if (mp[u] == 1) {
            u++;
            while (mp[u]>=2) u++;
        }
        cout << u << '\n';
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}