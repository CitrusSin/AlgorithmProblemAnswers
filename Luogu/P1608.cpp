#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

const u64 INF = -1;

vector<pair<u64, u64>> shortest_path_cnt(const vector<vector<pair<int, int>>>& graph, int start) {
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
    vector<u64> cnt(n, 0);

    notfound.emplace(start, 0);
    dists[start] = 0;
    cnt[start] = 1;

    for (size_t found_cnt=0; !notfound.empty() && found_cnt<n; found_cnt++) {
        int source;
        do {
            source = notfound.top().id;
            notfound.pop();
        } while (!notfound.empty() && found[source]);
        if (found[source]) break;
        found[source] = true;

        for (const pair<int, int>& conn : graph[source]) {
            int target = conn.first;
            u64 new_dist = conn.second + dists[source];

            if (!found[target]) {
                if (new_dist < dists[target]) {
                    dists[target] = new_dist;
                    cnt[target] = cnt[source];
                    notfound.emplace(target, new_dist);
                } else if (new_dist == dists[target]) {
                    cnt[target] += cnt[source];
                }
            }
        }
    }

    vector<pair<u64, u64>> result(n);
    for (int i=0; i<n; i++) {
        result[i].first = dists[i];
        result[i].second = cnt[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e;
    cin >> n >> e;

    vector<unordered_map<int, int>> pre_graph(n);
    while (e--) {
        int i, j, c;
        cin >> i >> j >> c;
        i--, j--;
        if (pre_graph[i].count(j)) {
            pre_graph[i][j] = min(pre_graph[i][j], c);
        } else {
            pre_graph[i][j] = c;
        }
    }

    vector<vector<pair<int, int>>> graph(n);
    for (int i=0; i<n; i++) {
        graph[i].assign(pre_graph[i].begin(), pre_graph[i].end());
    }

    vector<pair<u64, u64>> result = shortest_path_cnt(graph, 0);
    if (result[n-1].first == INF) {
        cout << "No answer" << endl;
    } else {
        cout << result[n-1].first << ' ' << result[n-1].second << endl;
    }
    return 0;
}