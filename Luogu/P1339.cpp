#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

vector<u64> shortest_path_all(const vector<vector<pair<int, u64>>>& graph, int start) {
    struct node {
        int id;
        int dist;
        node(int id, int dist) : id(id), dist(dist) {}
        bool operator<(const node& n2) const {
            return dist > n2.dist;
        }
    };

    size_t n = graph.size();

    vector<char> found(n, false);
    priority_queue<node> notfound;
    vector<u64> dists(n, -1);

    dists[start] = 0;
    notfound.emplace(start, 0);

    for (size_t found_cnt=0; !notfound.empty() && found_cnt < n; found_cnt++) {
        int source = notfound.top().id;
        notfound.pop();
        found[source] = true;

        for (const pair<int, u64> conn : graph[source]) {
            int target = conn.first;
            u64 new_dist = conn.second + dists[source];
            if (!found[target] && (new_dist < dists[target])) {
                dists[target] = new_dist;
                notfound.emplace(target, new_dist);
            }
        }
    }

    return dists;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;

    vector<vector<pair<int, u64>>> adjt(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adjt[u].emplace_back(v, w);
        adjt[v].emplace_back(u, w);
    } 

    vector<u64> dists = shortest_path_all(adjt, s);
    cout << dists[t] << endl;
    return 0;
}