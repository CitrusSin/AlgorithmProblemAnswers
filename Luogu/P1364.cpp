#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 INF = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<u64> number(n);
    vector<vector<u64>> graph(n, vector<u64>(n, INF));
    for (int i=0; i<n; i++) graph[i][i] = 0;

    for (int i=0; i<n; i++) {
        int w, u, v;
        cin >> w >> u >> v;
        u--, v--;
        number[i] = w;
        if (u >= 0) graph[i][u] = graph[u][i] = 1;
        if (v >= 0) graph[i][v] = graph[v][i] = 1;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    u64 min_dist = INF;
    for (int i=0; i<n; i++) {
        u64 dist = 0;
        for (int j=0; j<n; j++) {
            dist += graph[i][j] * number[j];
        }
        if (dist < min_dist) min_dist = dist;
    }

    cout << min_dist << endl;
    return 0;
}