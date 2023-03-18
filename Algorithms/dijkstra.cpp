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

        for (const pair<int, u64>& link : adjt[source]) {
            int target = link.first;
            u64 length = link.second + dist[source];
            if (!found[target]) {
                dist[target] = min<u64>(dist[target], length);
            }
        }
    }

    return dist;
}

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

    return 0;
}