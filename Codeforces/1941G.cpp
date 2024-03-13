#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<int> sp_dijkstra(const vector<set<int>>& graph, int src) {
    struct node {
        int id;
        int dist;

        node(int id, int dist) : id(id), dist(dist) {}

        bool operator<(const node& n2) const {
            return dist > n2.dist;
        }
    };

    size_t n = graph.size();

    vector<int> distance(n, -1);
    vector<char> found(n, false);
    priority_queue<node> notfound;

    distance[src] = 0;
    notfound.emplace(src, 0);

    while (!notfound.empty()) {
        int id;
        do {
            id = notfound.top().id;
            notfound.pop();
        } while (!notfound.empty() && found[id]);

        if (found[id]) break;

        found[id] = true;

        for (int nxt : graph[id]) {
            if (found[nxt]) continue;
            int new_dist = distance[id] + 1;
            if (distance[nxt] == -1 || distance[nxt] > new_dist) {
                distance[nxt] = new_dist;
                notfound.emplace(nxt, new_dist);
            }
        }
    }

    return distance;
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, int> color_map;
    vector<set<int>> graph(n);

    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;

        u--, v--;

        int pc;
        if (color_map.count(c)) {
            pc = color_map[c];
        } else {
            pc = graph.size();
            graph.push_back(set<int>());
            color_map[c] = pc;
        }

        graph[u].insert(pc);
        graph[pc].insert(u);
        graph[v].insert(pc);
        graph[pc].insert(v);
    }

    int b, e;
    cin >> b >> e;
    b--, e--;

    vector<int> dist = sp_dijkstra(graph, b);
    int ans = dist[e] / 2;

    cout << ans << '\n';
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