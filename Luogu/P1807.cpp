#include <bits/stdc++.h>

using namespace std;

vector<int> longest_path(const vector<vector<pair<int, int>>>& forward_graph, int start) {
    size_t n = forward_graph.size();
    vector<vector<pair<int, int>>> backward_graph(n);
    for (int i=0; i<n; i++) {
        for (const pair<int, int>& conn : forward_graph[i]) {
            backward_graph[conn.first].emplace_back(i, conn.second);
        }
    }

    vector<int> indegs(n, 0);
    queue<int> zero_indegs;
    for (int i=0; i<n; i++) {
        indegs[i] = backward_graph[i].size();
        if (indegs[i] == 0) {
            zero_indegs.push(i);
        }
    }

    vector<int> dists(n, numeric_limits<int>::min());
    dists[start] = 0;

    while (!zero_indegs.empty()) {
        size_t zs = zero_indegs.size();
        while (zs--) {
            int node = zero_indegs.front();
            zero_indegs.pop();

            for (const pair<int, int>& conn : forward_graph[node]) {
                indegs[conn.first]--;
                if (indegs[conn.first] == 0) {
                    zero_indegs.push(conn.first);
                }

                if (dists[conn.first] < dists[node] + conn.second) {
                    dists[conn.first] = dists[node] + conn.second;
                }
            }
        }
    }

    return dists;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(v, w);
    }

    vector<int> dists = longest_path(graph, 0);
    int dist = dists[n-1];
    if (dist == numeric_limits<int>::min()) dist = -1;
    cout << dist << endl;
    return 0;
}