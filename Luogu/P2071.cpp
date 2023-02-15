#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

bool dinitz_layer_bfs(
    const vector<unordered_map<int, u64>>& graph,
    vector<int>& layer,
    int s, int t
) {
    queue<int> bfsq;
    bfsq.push(s);
    layer[s] = 0;

    int cnt = 1;
    bool res = false;
    while (!bfsq.empty()) {
        size_t sq = bfsq.size();
        while (sq--) {
            int node = bfsq.front();
            bfsq.pop();

            if (node == t) {
                res = true;
            }

            for (const pair<int, u64>& conn : graph[node]) {
                if (conn.second > 0 && layer[conn.first] == -1) {
                    layer[conn.first] = cnt;
                    bfsq.push(conn.first);
                }
            }
        }
        cnt++;
    }

    return res;
}

u64 dinitz_extpath_dfs(
    vector<unordered_map<int, u64>>& graph,
    const vector<int>& layer,
    int s, int t, u64 max_flow
) {
    if (s == t) {
        return max_flow;
    }

    u64 total_flow = 0;
    for (const pair<int, u64>& path : graph[s]) {
        int next_node = path.first;
        u64 path_flow = path.second;
        if (
            path_flow > 0 &&
            layer[next_node] == layer[s]+1 &&
            (layer[next_node]<layer[t] || next_node == t)
        ) {
            u64 flow = dinitz_extpath_dfs(
                graph, layer, next_node, t,
                min(max_flow-total_flow, path_flow)
            );
            if (flow > 0) {
                graph[s][next_node] -= flow;
                graph[next_node][s] += flow;
                total_flow += flow;
            }
        }
    }
    return total_flow;
}

u64 max_flow_dinitz(const vector<unordered_map<int, u64>>& graph, int s, int t) {
    const u64 INF_U64 = numeric_limits<u64>::max();
    int n = graph.size();

    vector<unordered_map<int, u64>> revmap(n);
    for (int i=0; i<n; i++) {
        for (const pair<int, u64>& conn : graph[i]) {
            revmap[i][conn.first] += conn.second;
            revmap[conn.first][i] += 0;
        }
    }

    u64 total_flow = 0;
    vector<int> layer(n, -1);
    while (dinitz_layer_bfs(revmap, layer, s, t)) {
        total_flow += dinitz_extpath_dfs(revmap, layer, s, t, INF_U64);
        layer.assign(n, -1);
    }

    return total_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<unordered_map<int, u64>> graph(3*n+2);
    for (int i=0; i<2*n; i++) {
        int s1, s2;
        cin >> s1 >> s2;
        s1--, s2--;
        graph[i+2][s1+2*n+2] = 1;
        graph[i+2][s2+2*n+2] = 1;
    }

    for (int i=0; i<2*n; i++) {
        graph[0][i+2] = 1;
    }
    for (int i=0; i<n; i++) {
        graph[i+2*n+2][1] = 2;
    }

    u64 flow = max_flow_dinitz(graph, 0, 1);
    cout << flow << endl;
    return 0;
}