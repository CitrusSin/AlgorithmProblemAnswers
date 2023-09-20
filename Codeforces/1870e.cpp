#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> mps;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        mps[a]++;
    }

    uint32_t mex = 0;
    for (const pair<int, int>& p : mps) {
        if (p.first == mex) {
            mex++;
        } else break;
    }

    if (mex == 0) {
        cout << 0 << '\n';
        return;
    }

    vector<int> rec(mex);
    for (int i=0; i<mex; i++) {
        rec[i] = mps[i];
    }

    uint32_t ans = mex;

    uint32_t mask = ~(0xffffffff << (int(log2(mex))+1));
    uint32_t prop = (~mex) & mask;

    for (int i=0; i<mex; i++) {
        rec[i]--;
        if (rec[i] == 0) {
            mex = i;
            break;
        }
    }
    
    if (prop > mex) {
        uint32_t msk;
        for (msk = 0xffffffff; (prop & msk) > mex; msk >>= 1) {}
        prop = prop & msk;
    }

    ans ^= prop;

    cout << ans << '\n';
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