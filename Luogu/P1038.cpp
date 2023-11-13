#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> topsort(const vector<vector<pair<int, int>>> backward_graph) {
    size_t n = backward_graph.size();

    vector<vector<int>> forward_graph(n);
    for (int i=0; i<n; i++) {
        for (const pair<int, int>& p : backward_graph[i]) {
            forward_graph[p.first].push_back(i);
        }
    }
    
    vector<int> indegs(n, 0);
    for (int i=0; i<n; i++) {
        indegs[i] = backward_graph[i].size();
    }
    queue<int> zero_indegs;
    vector<vector<int>> result;
    for (int i=0; i<n; i++) {
        if (backward_graph[i].empty()) {
            zero_indegs.push(i);
        }
    }

    while (!zero_indegs.empty()) {
        vector<int> nodes;
        size_t zs = zero_indegs.size();
        while (zs--) {
            int id = zero_indegs.front();
            zero_indegs.pop();
            nodes.push_back(id);
            for (int i : forward_graph[id]) {
                indegs[i]--;
                if (indegs[i] == 0) {
                    zero_indegs.push(i);
                }
            }
        }
        result.push_back(nodes);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> neuro_net_state;
    for (int i=0; i<n; i++) {
        int s, u;
        cin >> s >> u;
        neuro_net_state.emplace_back(s, u);
    }

    vector<vector<pair<int, int>>> backward_graph(n);
    while (p--) {
        int i, j, w;
        cin >> i >> j >> w;
        i--, j--;
        backward_graph[j].emplace_back(i, w);
    }

    vector<vector<int>> layers = topsort(backward_graph);
    for (auto it = layers.begin()+1; it != layers.end(); it++) {
        vector<int>& neuro = *it;
        for (int id : neuro) {
            int res = 0;
            for (pair<int, int>& conn : backward_graph[id]) {
                res += neuro_net_state[conn.first].first * conn.second;
            }
            res -= neuro_net_state[id].second;
            if (res < 0) res = 0;
            neuro_net_state[id].first = res;
        }
    }

    vector<int>& back_nodes = layers.back();
    sort(back_nodes.begin(), back_nodes.end());

    bool flag = false;
    for (int id : back_nodes) {
        int val = neuro_net_state[id].first;
        if (val > 0) {
            cout << id+1 << ' ' << neuro_net_state[id].first << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "NULL" << endl;
    }
    return 0;
}