#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

vector<i64> dijkstra(const vector<map<i64, i64>>& graph, i64 start) {
    struct node {
        i64 id;
        i64 dist;

        node(i64 id, i64 dist) : id(id), dist(dist) {}

        bool operator<(const node& n2) const {
            return dist > n2.dist;
        }
    };

    size_t n = graph.size();

    vector<i64> dist(n, -1);
    vector<char> found(n, false);
    priority_queue<node> notfound;
    //found[start] = true;
    dist[start] = 0;
    notfound.emplace(start, 0);

    for (i64 t=0; t<n; t++) {
        i64 id = notfound.top().id;
        while (!notfound.empty() && found[id]) {
            notfound.pop();
            id = notfound.top().id;
        }
        if (found[id]) {
            return dist;
        }
        found[id] = true;
        
        for (auto [next, nxdist] : graph[id]) {
            if (found[next]) continue;
            if (dist[next] == -1 || dist[next] > dist[id] + nxdist) {
                dist[next] = dist[id] + nxdist;
                notfound.emplace(next, dist[next]);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, m;
    cin >> n >> m;

    vector<i64> a(n);
    for (i64 i=0; i<n; i++) cin >> a[i];

    vector<map<i64, i64>> graph(n);
    for (i64 i=0; i<m; i++) {
        i64 u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        graph[u][v] = graph[v][u] = 2*b + a[u] + a[v];
    }

    vector<i64> sp = dijkstra(graph, 0);

    for (i64 i=1; i<n; i++) {
        i64 dd = (sp[i] + a[0] + a[i]) / 2;
        if (i != 1) cout << ' ';
        cout << dd;
    }
    cout << '\n';
    return 0;
}