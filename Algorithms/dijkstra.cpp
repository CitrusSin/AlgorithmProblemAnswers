#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;

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
