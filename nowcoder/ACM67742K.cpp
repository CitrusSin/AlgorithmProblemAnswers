#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string pat;
    cin >> pat;
    
    int64_t y;
    cin >> y;
    
    map<char, int> mp;
    int cc = 0;
    for (int i=0; i<pat.size(); i++) {
        if (pat[i] >= 'a' && pat[i] <= 'd' && !mp.count(pat[i])) {
            mp[pat[i]] = cc++;
        }
    }
    
    vector<vector<int>> idxs(cc);
    int slash = -1;
    for (int i=0; i<pat.size(); i++) {
        if (pat[i] >= 'a' && pat[i] <= 'd') {
            idxs[mp[pat[i]]].push_back(i);
        } else if (pat[i] == '_') {
            slash = i;
        }
    }
    
    unordered_set<int64_t> totals;
    int uplim = 1;
    for (int i=0; i<cc; i++) uplim *= 10;
    
    if (slash != -1) {
        for (int k=0; k<uplim; k++) {
            set<int> digs;
            int ku = k;
            for (int t=0; t<cc; t++) {
                int v = ku % 10;
                digs.insert(v);
                for (int i : idxs[t]) {
                    pat[i] = v + '0';
                }
                ku /= 10;
            }
            if (digs.size() != cc) continue;
            
            for (int sl=0; sl <= 9; sl++) {
                pat[slash] = sl + '0';
                if (pat[0] == '0' && pat.size() > 1) continue;

                stringstream ss(pat);

                int64_t ans;
                ss >> ans;
                if (ans % 8 != 0) continue;
                if (ans > y) continue;
                totals.insert(ans);
            }
        }
    } else {
        for (int k=0; k<uplim; k++) {
            set<int> digs;
            int ku = k;
            for (int t=0; t<cc; t++) {
                int v = ku % 10;
                digs.insert(v);
                for (int i : idxs[t]) {
                    pat[i] = v + '0';
                }
                ku /= 10;
            }
            if (digs.size() != cc) continue;
            
            if (pat[0] == '0' && pat.size() > 1) continue;

            stringstream ss(pat);

            int64_t ans;
            ss >> ans;
            if (ans % 8 != 0) continue;
            if (ans > y) continue;
            totals.insert(ans);
        }
    }
    
    
    cout << totals.size() << endl;
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