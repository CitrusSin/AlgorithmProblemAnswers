#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    
    vector<i64> spf;
    while (q--) {
        i64 t, v;
        cin >> t >> v;
        if (t > 0) {
            spf.erase(spf.end() - t, spf.end());
        }
        i64 p = spf.size();
        i64 pv = (p+1) * v % MOD;
        if (!spf.empty()) pv = (pv + spf.back()) % MOD;
        spf.push_back(pv);

        cout << pv << '\n';
    }
    return 0;
}
