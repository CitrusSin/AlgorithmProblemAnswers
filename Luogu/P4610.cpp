#include <bits/stdc++.h>

using namespace std;

vector<unordered_map<int, int>> rev_graph(const vector<unordered_map<int, int>>& g) {
    int n = g.size();
    vector<unordered_map<int, int>> g2(n);
    for (int i=0; i<n; i++) {
        for (const auto &conn : g[i]) {
            g2[conn.first][i] = 1;
        }
    }
    return g2;
}

void dfs_path(
    int src,
    int dest,
    const vector<unordered_map<int, int>>& graph,
    const vector<unordered_map<int, int>>& revg,
    vector<int>& front_record,
    vector<int>& back_record,
    vector<char>& mark,
    const function<void(const vector<int>&)>& callback
) {
    if (src == dest) {
        vector<int> path(front_record.begin(), front_record.end());
        path.push_back(src);
        for (auto it = back_record.rbegin(); it != back_record.rend(); it++) {
            path.push_back(*it);
        }
        callback(path);
        return;
    }
    mark[src] = true;
    mark[dest] = true;
    front_record.push_back(src);
    back_record.push_back(dest);
    for (const auto &s2p : graph[src]) {
        if (s2p.first == dest) {
            vector<int> path(front_record.begin(), front_record.end());
            for (auto it = back_record.rbegin(); it != back_record.rend(); it++) {
                path.push_back(*it);
            }
            callback(path);
        } else if (!mark[s2p.first]) {
            for (const auto &d2p : revg[dest]) {
                if (!mark[d2p.first]) {
                    dfs_path(s2p.first, d2p.first, graph, revg, front_record, back_record, mark, callback);
                }
            }
        }
    }
    front_record.pop_back();
    back_record.pop_back();
    mark[dest] = false;
    mark[src] = false;
}

void dfs_path(
    int src,
    int dest,
    const vector<unordered_map<int, int>>& graph,
    const function<void(const vector<int>&)>& callback
) {
    size_t n = graph.size();
    vector<unordered_map<int, int>> rev_map = rev_graph(graph);
    vector<int> front_record, back_record;
    vector<char> mark(n, false);
    dfs_path(src, dest, graph, rev_map, front_record, back_record, mark, callback);
}

vector<int> dijkstra_shortest(int src, const vector<unordered_map<int, int>>& graph) {
    struct node {
        int n;
        int dist;
        node(int n, int dist) : n(n), dist(dist) {}
        bool operator<(const node& n2) const {
            if (dist == -1) {
                return n2.dist >= 0;
            } else if (n2.dist == -1) {
                return false;
            }
            return dist > n2.dist;
        }
    };
    
    size_t n = graph.size();
    vector<int> dists(n, -1);
    dists[src] = 0;
    priority_queue<node> notfound;
    notfound.emplace(src, 0);
    vector<char> found(n, false);
    while (!notfound.empty()) {
        node nxt = notfound.top();
        notfound.pop();
        if (found[nxt.n]) continue;
        found[nxt.n] = true;

        int nx = nxt.n;
        for (const auto &conn : graph[nxt.n]) {
            int target = conn.first;
            int d2 = dists[nx] + conn.second;
            if (dists[target] == -1 || dists[target] > d2) {
                dists[target] = d2;
                notfound.emplace(target, d2);
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
    vector<unordered_map<int, int>> graph(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--,b--;
        graph[a][b] = 1;
    }

    int min_len = numeric_limits<int>::max();
    dfs_path(0, 1, graph, [&graph, &min_len](const vector<int>& path) {
        vector<unordered_map<int, int>> g2 = graph;
        int l1 = path.size();
        for (int nd : path) {
            for (auto& conn : g2[nd]) {
                conn.second = 0;
            }
        }
        vector<int> sl = dijkstra_shortest(1, g2);
        min_len = min(min_len, l1 + sl[0]);
    });

    cout << min_len << endl;
    return 0;
}