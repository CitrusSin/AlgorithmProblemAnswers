#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<unordered_set<int>> graph(n);
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    while (true) {
        vector<int> deg1;
        for (int i=0; i<n; i++) {
            if (graph[i].size() == 1) {
                deg1.push_back(i);
            }
        }
        if (deg1.size() == 0) {
            break;
        }
        for (int p : deg1) {
            int q = *graph[p].begin();
            graph[p].clear();
            graph[q].erase(p);
        }
    }
    vector<int> node_loop;
    for (int i=0; i<n; i++) {
        if (graph[i].size() > 1) {
            node_loop.push_back(i);
        }
    }
    sort(node_loop.begin(), node_loop.end());

    bool flag = false;
    for (int p : node_loop) {
        if (flag) {
            cout << ' ';
        } else {
            flag = true;
        }
        cout << (p+1);
    }
    cout << endl;
    return 0;
}