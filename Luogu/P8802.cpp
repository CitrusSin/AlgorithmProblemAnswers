#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

vector<u64> shortest_path(const vector<vector<pair<int, u64>>>& graph, int start) {
    struct node {
        int id;
        u64 dist;
        node(int id, u64 dist) : id(id), dist(dist) {}
        bool operator<(const node& n2) const {
            return dist > n2.dist;
        }
    };
    
    size_t n = graph.size();

    vector<char> found(n, false);
    priority_queue<node> notfound;
    vector<u64> dist(n, -1);

    dist[start] = 0;
    notfound.emplace(start, 0);

    for (size_t found_cnt=0; !notfound.empty() && found_cnt < n; found_cnt++) {
        int src;
        do {
            src = notfound.top().id;
            notfound.pop();
        } while (!notfound.empty() && found[src]);
        if (found[src]) break;
        found[src] = true;

        for (const pair<int, u64> conn : graph[src]) {
            int target = conn.first;
            u64 new_dist = conn.second + dist[src];
            if (!found[target] && new_dist < dist[target]) {
                dist[target] = new_dist;
                notfound.emplace(target, new_dist);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> quarantine_times(n);

    for (int i=0; i<n; i++) {
        cin >> quarantine_times[i];
    }

    vector<vector<pair<int, u64>>> graph(n);

    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        graph[u].emplace_back(v, quarantine_times[u]+c);
        graph[v].emplace_back(u, quarantine_times[v]+c);
    }

    vector<u64> mp = shortest_path(graph, 0);
    cout << mp[n-1] - quarantine_times[0] << endl;
    return 0;
}