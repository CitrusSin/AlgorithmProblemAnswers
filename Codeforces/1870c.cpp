#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, vector<int>> rev_tab;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
        rev_tab[a[i]].push_back(i);
    }

    set<int> indices;
    for (int i=0; i<n; i++) indices.insert(i);
    
    vector<int> ans(k, 0);
    for (const pair<int, vector<int>>& p : rev_tab) {
        int val = p.first;
        ans[val] = ((*indices.rbegin()) - (*indices.begin()) + 1) * 2;
        for (int i : p.second) {
            indices.erase(i);
        }
    }

    for (int i=0; i<k; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
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