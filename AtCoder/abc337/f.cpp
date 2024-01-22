#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n), cc(n, 0);
    for (int i=0; i<n; i++) {
        cin >> c[i];
        c[i]--;
        cc[c[i]]++;
    }

    unordered_map<int, int> occ;
    int sp = 0, ep = 0;
    for (ep = 0; ep<n && occ.size() < m; ep++) {
        occ[c[ep]]++;
    }
    int ttl = 0;
    for (auto [cl, cnt] : occ) {
        ttl += min(k, cc[cl]);
    }
    for (sp = 0; sp<n; sp++) {
        cout << ttl << endl;

        occ[c[sp]]--;
        if (occ[c[sp]] == 0) {
            occ.erase(c[sp]);
            ttl -= min(k, cc[c[sp]]);
            while (occ.size() < m && ep - sp - 1 < n) {
                occ[c[ep%n]]++;
                if (occ[c[ep%n]] == 1) ttl += min(k, cc[c[ep%n]]);
                ep++;
            }
        }
    }

    return 0;
}