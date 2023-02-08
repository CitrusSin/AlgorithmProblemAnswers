#include <bits/stdc++.h>
using namespace std;

vector<int> topsort(const vector<vector<int>>& forward_graph) {
    size_t n = forward_graph.size();
    
    vector<vector<int>> backward_graph(n);
    for (int i=0; i<n; i++) {
        for (int j : forward_graph[i]) {
            backward_graph[j].push_back(i);
        }
    }

    vector<int> indegs(n);
    priority_queue<int> zero_indegs;
    for (int i=0; i<n; i++) {
        indegs[i] = backward_graph[i].size();
        if (indegs[i] == 0) zero_indegs.push(i);
    }

    vector<int> result;

    size_t node_cnt = 0;
    while (!zero_indegs.empty()) {
        size_t s = zero_indegs.size();
        while (s--) {
            int id = zero_indegs.top();
            zero_indegs.pop();

            result.push_back(id);
            node_cnt++;
            for (int fwid : forward_graph[id]) {
                indegs[fwid]--;
                if (indegs[fwid] == 0) {
                    zero_indegs.push(fwid);
                }
            }
        }
    }

    if (node_cnt < n) {
        throw logic_error("Loop in graph");
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<unordered_set<int>> forward_graph_set(n);
        while (m--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            forward_graph_set[x].insert(y);
        }
        vector<vector<int>> backward_graph(n);
        for (int i=0; i<n; i++) {
            for (int j : forward_graph_set[i]) {
                backward_graph[j].push_back(i);
            }
        }

        try {
            vector<int> layers = topsort(backward_graph);
            for (auto it = layers.crbegin(); it != layers.crend(); it++) {
                cout << *it+1 << " ";
            }
            cout << endl;
        } catch (logic_error err) {
            cout << "Impossible!" << endl;
        }
    }
    return 0;
}