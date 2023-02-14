#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

bool dinic_layer_bfs(
    const vector<unordered_map<int, u64>>& graph,
    vector<int>& layer,
    int s, int t
) {
    queue<int> nodes;
    nodes.push(s);
    layer[s] = 0;

    int cnt = 0;
    bool result = false;
    while (!nodes.empty()) {
        size_t ql = nodes.size();
        while (ql--) {
            int node = nodes.front();
            nodes.pop();

            if (node == t) result = true;
            for (const pair<int, u64>& conn : graph[node]) {
                if (layer[conn.first] == -1 && conn.second > 0) {
                    nodes.push(conn.first);
                    layer[conn.first] = cnt+1;
                }
            }
        }
        cnt++;
    }

    return result;
}

u64 dinic_extpath_dfs(
    vector<unordered_map<int, u64>>& graph,
    const vector<int>& layer,
    int s, int t, u64 max_flow
) {
    if (s == t) return max_flow;

    int terminate_layer = layer[t];
    u64 total_flow = 0;
    for (pair<const int, u64>& conn : graph[s]) {
        if (
            conn.second > 0 &&
            layer[conn.first] == layer[s]+1 &&
            (layer[conn.first] < terminate_layer || conn.first == t)
        ) {
            u64 flow = dinic_extpath_dfs(graph, layer, conn.first, t, min(max_flow - total_flow, conn.second));
            if (flow > 0) {
                graph[s][conn.first] -= flow;
                graph[conn.first][s] += flow;
                total_flow += flow;
            }
            if (total_flow == max_flow) break;
        }
    }
    return total_flow;
}

u64 max_flow_dinic(const vector<unordered_map<int, u64>>& graph, int s, int t) {
    const u64 INF_U64 = numeric_limits<u64>::max();

    if (s == t) return INF_U64;

    int n = graph.size();
    vector<unordered_map<int, u64>> graph_rev(n);
    for (int i=0; i<n; i++) {
        for (const auto& conn : graph[i]) {
            graph_rev[i][conn.first] += conn.second;
            graph_rev[conn.first][i] += 0;
        }
    }

    u64 flow = 0;
    vector<int> layer(n, -1);
    while (dinic_layer_bfs(graph_rev, layer, s, t)) {
        flow += dinic_extpath_dfs(graph_rev, layer, s, t, INF_U64);
        layer.assign(n, -1);
    }

    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<unordered_map<int, u64>> graph(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u][v] = w;
    }

    u64 flow = max_flow_dinic(graph, s, t);
    cout << flow << endl;
    return 0;
}