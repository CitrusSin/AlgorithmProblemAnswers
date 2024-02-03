#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    vector<pair<int, int>> cps;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cps.emplace_back(u, v);
    }
    
    int maxstate = n;
    
    function<void(int)> f = [&](int idx) {
        if (idx == cps.size()) {
            vector<int> ind(n);
            for (int i=0; i<n; i++) ind[i] = i;
            sort(ind.begin(), ind.end(), [&](int x, int y) {return a[x] > a[y];});
            int r = 0;
            for (int rnk=0; rnk<n; rnk++) {
                if (ind[rnk] == 0) {
                    r = rnk;
                    while (r > 0 && a[ind[r]] == a[ind[r-1]]) r--;
                    break;
                }
            }
            maxstate = min(maxstate, r);
            return;
        }
        
        int u = cps[idx].first, v = cps[idx].second;
        if (u > v) swap(u, v);
        a[u] += 3;
        f(idx+1);
        if (u != 0) {
            a[u] -= 3;
            a[v] += 3;
            f(idx+1);
            a[v] -= 2;
            a[u] += 1;
            f(idx+1);
            a[u] -= 1;
            a[v] -= 1;
        } else {
            a[u] -= 3;
        }
    };
    
    f(0);
    maxstate++;
    cout << maxstate << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}