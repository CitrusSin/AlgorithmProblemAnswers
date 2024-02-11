#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> col(n);
    for (int i=0; i<n; i++) {
        cin >> col[i];
        col[i]--;
    }
    vector<int> colors = col;
    sort(colors.begin(), colors.end());
    colors.erase(unique(colors.begin(), colors.end()), colors.end());
    
    map<int, int> cq;
    for (int i=0; i<colors.size(); i++) {
        cq[colors[i]] = i;
    }
    
    vector<vector<int>> colts(colors.size());
    
    for (int i=0; i<n; i++) {
        colts[cq[col[i]]].push_back(i);
    }
    
    int len = n, cnt = 0;
    while (len > 0) {
        int total_found = 0, min_pos = len;
        for (int i=0; i<colors.size(); i++) {
            int lpos = lower_bound(colts[i].begin(), colts[i].end(), len) - colts[i].begin() - 1;
            if (lpos < 0) continue;
            lpos = colts[i][lpos];
            total_found++;
            min_pos = min(min_pos, lpos);
        }
        if (total_found < 2) {
            break;
        }
        cnt++;
        len = min_pos;
    }
    cnt += len;
    
    cout << cnt << '\n';
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
}