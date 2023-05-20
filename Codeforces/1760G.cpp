#include <bits/stdc++.h>

using namespace std;

void dfs(
    const vector<unordered_map<int, int>>& graph,
    vector<optional<int>>& record,
    int node,
    int stop_cond = -1,
    int x = 0,
    int root = -1
) {
    record[node] = x;
    for (const pair<int, int>& conn : graph[node]) {
        if (conn.first != root && conn.first != stop_cond) {
            dfs(graph, record, conn.first, stop_cond, x^conn.second, node);
        }
    }
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<unordered_map<int, int>> graph(n);
    for (int i=0; i<n-1; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        l--, r--;
        graph[l][r] = graph[r][l] = w;
    }

    vector<optional<int>> xor_rst_a(n), xor_rst_b(n);
    dfs(graph, xor_rst_a, a, b);
    dfs(graph, xor_rst_b, b, b);

    set<int> lookup;
    for (int i=0; i<n; i++) {
        if (i == b) continue;
        if (xor_rst_a[i].has_value()) lookup.insert(xor_rst_a[i].value());
    }

    for (int i=0; i<n; i++) {
        if (i == b) continue;
        if (xor_rst_b[i].has_value() && lookup.count(xor_rst_b[i].value())) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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