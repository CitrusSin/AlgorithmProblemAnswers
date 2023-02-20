#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> topsort(const vector<vector<int>>& backward_graph, const vector<int>& start) {
    int n = backward_graph.size();
    
    vector<vector<int>> forward_graph(n);
    for (int i=0; i<n; i++) {
        for (int j : backward_graph[i]) {
            forward_graph[j].push_back(i);
        }
    }

    vector<int> indegs(n, -1);
    queue<int> zero_indegs;
    for (int i : start) {
        indegs[i] = 0;
        zero_indegs.push(i);
    }
    for (int i=0; i<n; i++) {
        int prev = indegs[i];
        indegs[i] = backward_graph[i].size();
        if (prev == -1 && indegs[i] == 0) {
            indegs[i] = 1;
        }
    }

    vector<vector<int>> result;

    while (!zero_indegs.empty()) {
        vector<int> layer;
        size_t s = zero_indegs.size();
        while (s--) {
            int id = zero_indegs.front();
            zero_indegs.pop();
            layer.push_back(id);

            for (int next : forward_graph[id]) {
                indegs[next]--;
                if (indegs[next] == 0) zero_indegs.push(next);
            }
        }
        result.push_back(std::move(layer));
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, p;
    cin >> n >> k >> p;

    vector<int> init(p);
    for (int i=0; i<p; i++) {
        cin >> init[i];
        init[i]--;
    }

    vector<vector<int>> backward_graph(n);

    int r;
    cin >> r;
    while (r--) {
        int v, s;
        cin >> v >> s;
        v--;
        while (s--) {
            int p;
            cin >> p;
            p--;
            backward_graph[v].push_back(p);
        }
    }

    vector<vector<int>> layers = topsort(backward_graph, init);
    int layer_cnt = layers.size();
    for (int i=0; i<layer_cnt; i++) {
        if (find(layers[i].begin(), layers[i].end(), k-1) != layers[i].end()) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}