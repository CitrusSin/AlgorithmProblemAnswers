#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

vector<u64> shortest_path_all(const vector<vector<pair<int, u64>>>& adjt, int start) {
    using vecbool = vector<char>;
    size_t n = adjt.size();

    vecbool found(n, false);
    vector<u64> dist(n, -1ll);
    size_t found_cnt = 0;
    dist[start] = 0;

    while (found_cnt < n) {
        int source = -1;
        for (size_t i=0; i<n; i++) {
            if (!found[i] && dist[i] >= 0 && (source < 0 || dist[i] < dist[source])) {
                source = i;
            }
        }
        if (source == -1) break;

        found[source] = true;
        found_cnt++;

        for (const pair<int, int>& link : adjt[source]) {
            int target = link.first;
            u64 length = link.second + dist[source];
            if (!found[target]) {
                dist[target] = min<u64>(dist[target], length);
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

    vector<vector<pair<int, u64>>> adjt(n), rev_adjt(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adjt[u].emplace_back(v, w);
        rev_adjt[v].emplace_back(u, w);
    }

    vector<u64> begin_dists = shortest_path_all(adjt, 0);
    vector<u64> rev_dists = shortest_path_all(rev_adjt, 0);
    u64 total_cost = 0;
    for (int i=1; i<n; i++) {
        total_cost += begin_dists[i] + rev_dists[i];
    }
    cout << total_cost << endl;
    return 0;
}