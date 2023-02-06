#include <bits/stdc++.h>

using namespace std;

typedef char BOOL;
#define TRUE 1
#define FALSE 0

bool find_extern_path(const vector< vector<int> >& graph, vector<int>& match, vector<BOOL>& mark, int start) {
    mark[start] = TRUE;
    for (int next : graph[start]) {
        if (mark[next]) continue;
        if (match[next] < 0) {
            match[next] = start;
            match[start] = next;

            mark[start] = FALSE;
            return true;
        } else if (!mark[match[next]]) {
            mark[next] = TRUE;
            bool res = find_extern_path(graph, match, mark, match[next]);
            if (res) {
                match[next] = start;
                match[start] = next;
                mark[match[next]] = FALSE;
                mark[next] = FALSE;
                mark[start] = FALSE;
                return true;
            }
            mark[match[next]] = FALSE;
            mark[next] = FALSE;
        }
    }
    mark[start] = FALSE;
    return false;
}

int max_match(const vector< vector<int> >& graph, int n) {
    size_t t = graph.size();
    vector<int> match(t, -1);
    vector<BOOL> mark(t, FALSE);

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (find_extern_path(graph, match, mark, i)) cnt++;
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > graph_table(n+m);
    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        while (s--) {
            int id;
            cin >> id;
            graph_table[i].push_back(n+id-1);
            graph_table[n+id-1].push_back(i);
        }
    }

    int total = max_match(graph_table, n);

    cout << total << endl;
    return 0;
}