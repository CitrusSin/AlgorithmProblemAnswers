#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

vector<u64> shortest_path(const vector<vector<pair<int, u64>>>& adjt, int start) {
    struct nfnode {
        int id;
        u64 dist;
        nfnode(int id, int dist) : id(id), dist(dist) {}
        bool operator<(const nfnode& n) const {
            return dist > n.dist;
        }
    };
    using vecbool = vector<char>;

    size_t n = adjt.size();

    vecbool found(n, false);
    priority_queue<nfnode> notfound;
    notfound.emplace(start, 0);
    vector<u64> dist(n, -1ll);
    size_t found_cnt = 0;
    dist[start] = 0;

    while (!notfound.empty() && found_cnt < n) {
        int source;
        do {
            source = notfound.top().id;
            notfound.pop();
        } while (!notfound.empty() && found[source]);
        if (found[source]) break;
        found[source] = true;
        found_cnt++;

        for (const pair<int, int>& link : adjt[source]) {
            int target = link.first;
            u64 length = link.second + dist[source];
            if (!found[target] && length < dist[target]) {
                dist[target] = length;
                notfound.emplace(target, length);
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
    
    vector<vector<pair<int, u64>>> graph(n), rev_graph(n);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(v, w);
        rev_graph[v].emplace_back(u, w);
    }

    vector<u64> dist = shortest_path(graph, 0), rev_dist = shortest_path(rev_graph, 0);
    u64 total = 0;
    for (int i=1; i<n; i++) {

        total += dist[i] + rev_dist[i];
    }
    cout << total << endl;
    return 0;
}