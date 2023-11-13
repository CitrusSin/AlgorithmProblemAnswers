#include <bits/stdc++.h>

using namespace std;

void detect(const vector<unordered_set<int>>& gp, int& x, int& y) {
    int n = gp.size();
    
    int p = 0;
    if (gp[p].size() == 1) {
        p = *gp[p].begin();
    }

    bool flag = true;
    vector<char> vis(n, false);
    vis[p] = true;
    queue<int> bfsq;
    bfsq.push(p);

    int max_depth = 0;
    while (!bfsq.empty()) {
        size_t sp = bfsq.size();
        while (sp--) {
            int d = bfsq.front();
            bfsq.pop();

            for (int nxt : gp[d]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                bfsq.push(nxt);
            }
        }
        max_depth++;
    }
    if (max_depth > 3) {
        for (int r : gp[p]) {
            if (gp[r].size() != 1) {
                p = r;
                break;
            }
        }
    }
    x = gp[p].size();
    y = gp[*gp[p].begin()].size()-1;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> gp(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        gp[u].insert(v);
        gp[v].insert(u);
    }

    int x, y;
    detect(gp, x, y);
    cout << x << ' ' << y << endl;
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