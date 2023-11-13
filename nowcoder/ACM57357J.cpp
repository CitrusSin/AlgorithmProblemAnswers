#include <bits/stdc++.h>

using namespace std;

vector<int> toposort(const vector<unordered_set<int>>& g) {
    int n = g.size();

    vector<int> indegs(n, 0);

    for (int i=0; i<n; i++) {
        for (int v : g[i]) {
            indegs[v]++;
        }
    }

    queue<int> zids;
    for (int i=0; i<n; i++) {
        if (indegs[i] == 0) {
            zids.push(i);
        }
    }

    vector<int> result;
    while (!zids.empty()) {
        int nd = zids.front();
        zids.pop();

        result.push_back(nd);
        for (int v : g[nd]) {
            indegs[v]--;
            if (indegs[v] == 0) {
                zids.push(v);
            }
        }
    }

    return result;
}

void solve(vector<unordered_set<int>>& g, vector<vector<int>>& results) {
    int n = g.size();
    
    vector<int> seq = toposort(g);
    if (seq.size() == g.size()) {
        results.push_back(seq);
    } else {
        vector<int> vp(n);
        for (int i=0; i<n; i++) vp[i] = i;
        results.push_back(vp);
        reverse(vp.begin(), vp.end());
        results.push_back(vp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
    }

    vector<vector<int>> results;
    solve(g, results);

    cout << results.size() << endl;
    for (const vector<int>& vc : results) {
        for (int i=0; i<n; i++) {
            if (i) cout << ' ';
            cout << (vc[i]+1);
        }
        cout << endl;
    }

    return 0;
}