#include <bits/stdc++.h>

using namespace std;

bool check_digram(const vector<unordered_set<int>>& graph) {
    size_t n = graph.size();
    vector<optional<bool>> res(n);
    queue<int> bfsq;
    for (int r=0; r<n; r++) {
        if (res[r].has_value()) continue;
        res[r] = true;
        bfsq.push(r);
        while (!bfsq.empty()) {
            int i = bfsq.front();
            bfsq.pop();
            for (int nxt : graph[i]) {
                if (res[nxt].has_value() && res[nxt].value() == res[i].value()) {
                    return false;
                }
                if (!res[nxt].has_value()) {
                    res[nxt] = !res[i].value();
                    bfsq.push(nxt);
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int i=0; i<m; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<unordered_set<int>> graph(n);
    for (int i=0; i<m; i++) {
        graph[a[i]].insert(b[i]);
        graph[b[i]].insert(a[i]);
    }

    cout << (check_digram(graph) ? "Yes" : "No") << endl;
    return 0;
}