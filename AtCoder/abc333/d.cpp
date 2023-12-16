#include <functional>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int delete_count(const vector<vector<int>>& graph, int node) {
    int n = graph.size();
    
    vector<int> fa(n);
    function<void(int, int)> dfs = [&](int nd, int f) {
        fa[nd] = f;
        for (int ch : graph[nd]) {
            if (ch != f) dfs(ch, nd);
        }
    };
    dfs(node, -1);

    vector<int> ans(n, 0);
    function<int(int)> fn = [&](int idx) -> int {
        if (ans[idx]) return ans[idx];
        if (graph[idx].size() == 1) return ans[idx] = 1;

        int sum_opr = 1, max_opr = 0;
        for (int ch : graph[idx]) {
            if (ch == fa[idx]) continue;
            int val = fn(ch);
            sum_opr += val;
            max_opr = max(max_opr, val);
        }
        if (fa[idx] == -1) return sum_opr - max_opr;
        return ans[idx] = sum_opr;
    };

    return fn(node);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << delete_count(graph, 0) << endl;
    return 0;
}