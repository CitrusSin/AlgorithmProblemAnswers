#include <bits/stdc++.h>

using namespace std;

bool extern_path(const vector< vector<int> >& graph, vector<int>& match, vector<char>& mark, int start) {
    mark[start] = true;
    for (int next : graph[start]) {
        if (mark[next]) continue;
        if (match[next] == -1) {
            match[next] = start;
            match[start] = next;

            mark[start] = false;
            return true;
        } else if (!mark[match[next]]) {
            mark[next] = true;
            bool res = extern_path(graph, match, mark, match[next]);
            if (res) {
                match[next] = start;
                match[start] = next;
                
                mark[start] = false;
                mark[next] = false;
                return true;
            }
            mark[next] = false;
        }
    }
    mark[start] = false;
    return false;
}

int max_match(const vector< vector<int> >& graph, int p) {
    size_t n = graph.size();
    vector<int> match(n, -1);
    vector<char> mark(n, false);
    
    int cnt = 0;
    for (int i=0; i<p; i++) {
        if (extern_path(graph, match, mark, i)) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, e;
    cin >> n >> m >> e;
    vector< set<int> > adjt(n+m);
    while (e--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjt[u].insert(n+v);
        adjt[n+v].insert(u);
    }
    vector< vector<int> > graph(n+m);
    for (int i=0; i<n+m; i++) {
        for (int p : adjt[i]) {
            graph[i].push_back(p);
        }
    }

    int cnt = max_match(graph, n);
    cout << cnt << endl;
    return 0;
}