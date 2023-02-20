#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

const int mod = 100003;

vector<int> shortest_path_count_all(const vector<vector<pair<int, u64>>>& adjt, int start) {
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
    notfound.emplace(0, 0);
    vector<u64> dist(n, -1ll);
    vector<int> cnt(n, 0);
    cnt[start] = 1;
    size_t found_cnt = 0;
    dist[start] = 0;

    while (!notfound.empty()) {
        int source = notfound.top().id;

        found[source] = true;
        found_cnt++;
        notfound.pop();

        for (const pair<int, int>& link : adjt[source]) {
            int target = link.first;
            u64 length = link.second + dist[source];
            if (!found[target]) {
                if (length < dist[target]) {
                    notfound.emplace(target, length);
                    dist[target] = length;
                    cnt[target] = cnt[source];
                } else if (length == dist[target]) {
                    cnt[target] += cnt[source];
                    cnt[target] %= mod;
                }
            }
        }
    }

    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, u64>>> adjt(n);

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adjt[x].emplace_back(y, 1);
        adjt[y].emplace_back(x, 1);
    }

    vector<int> cntarr = shortest_path_count_all(adjt, 0);
    for (int i=0; i<n; i++) {
        cout << cntarr[i] << endl;
    }
    return 0;
}