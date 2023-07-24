#include <bits/stdc++.h>

using namespace std;

int count_tree(vector<int>& ca, const vector<unordered_set<int>>& graph, int root = 0) {
    int n = graph.size();
    ca[root] = 0;
    for (int child : graph[root]) {
        if (ca[child] != -1) continue;
        ca[root] += count_tree(ca, graph, child);
    }
    if (ca[root] == 0) {
        ca[root] = 1;
    }
    return ca[root];
}

void solve() {
    int n;
    cin >> n;

    vector<unordered_set<int>> graph(n);
    for (int i=0; i<n-1; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        graph[p].insert(q);
        graph[q].insert(p);
    }

    vector<int> ca(n, -1);
    count_tree(ca, graph);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int64_t val = (int64_t)ca[x] * ca[y];
        cout << val << endl;
    }
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