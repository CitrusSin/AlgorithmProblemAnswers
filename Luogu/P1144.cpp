#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

const int mod = 100003;

vector<int> shortest_path_count_all(const vector<vector<pair<int, u64>>>& adjt, int start) {
    using vecbool = vector<char>;
    size_t n = adjt.size();

    vecbool found(n, false);
    vector<u64> dist(n, -1ll);
    vector<int> cnt(n, 0);
    size_t found_cnt = 0;
    dist[start] = 0;
    cnt[start] = 1;

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
                if (length < dist[target]) {
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