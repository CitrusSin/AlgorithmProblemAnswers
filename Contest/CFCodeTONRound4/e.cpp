#include <bits/stdc++.h>

using namespace std;

bool check_bfs(const vector<int>& dangers, const vector<vector<int>>& map_forward, int start) {
    struct node {
        int id;
        int cap_req;
        node(int id, int cap_req) : id(id), cap_req(cap_req) {}
        bool operator<(const node& n) const {
            return cap_req > n.cap_req;
        }
    };

    int n = dangers.size();
    
    int cap = 0;
    queue<int> bfsq;
    vector<char> visited(n, false);
    priority_queue<node> remaining;
    visited[start] = true;
    bfsq.push(start);
    while (!bfsq.empty() || !remaining.empty()) {
        if (bfsq.empty()) {
            bool flag = false;
            while (!remaining.empty() && cap >= remaining.top().cap_req) {
                flag = true;
                bfsq.push(remaining.top().id);
                remaining.pop();
            }
            if (!flag) return false;
        }
        size_t sq = bfsq.size();
        while (sq--) {
            while (!remaining.empty() && cap >= remaining.top().cap_req) {
                bfsq.push(remaining.top().id);
                remaining.pop();
            }
            int p = bfsq.front();
            bfsq.pop();
            cap++;
            for (int nxt : map_forward[p]) {
                if (!visited[nxt]) {
                    if (dangers[nxt] > cap) {
                        remaining.emplace(nxt, dangers[nxt]);
                    } else {
                        bfsq.push(nxt);
                    }
                    visited[nxt] = true;
                }
            }
        }
    }
    if (cap != n) return false;
    return true;
}

bool check(const vector<int>& dangers, const vector<vector<int>>& map_forward) {
    int n = dangers.size();
    
    for (int i=0; i<n; i++) {
        if (dangers[i] == 0) {
            if (check_bfs(dangers, map_forward, i)) return true;
        }
    }
    return false;
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
        vector<int> dangers(n);
        vector<vector<int>> map_forward(n);
        for (int i=0; i<n; i++) {
            cin >> dangers[i];
        }
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (u != v) {
                map_forward[u].push_back(v);
                map_forward[v].push_back(u);
            }
        }

        cout << (check(dangers, map_forward)?"YES":"NO") << endl;
    }
    return 0;
}