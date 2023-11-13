#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

vector<u64> shortest_path_all_heap(const vector<vector<pair<int, u64>>>& adjt, int start) {
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

        for (const pair<int, u64>& link : adjt[source]) {
            int target = link.first;
            u64 length = max(link.second, dist[source]);
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

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;

    vector<vector<pair<int, u64>>> graph(n);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<u64> resis = shortest_path_all_heap(graph, s);
    cout << resis[t] << endl;
    return 0;
}