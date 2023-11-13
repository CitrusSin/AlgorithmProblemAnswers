#include <bits/stdc++.h>

using namespace std;

class DSU {
private:
    vector<int> data;
public:
    DSU(int n) : data(n, -1) {}

    int head(int node) {
        if (data[node] == -1) return node;
        return data[node] = head(data[node]);
    }

    bool query(int a, int b) {
        return head(a) == head(b);
    }
    
    void merge(int a, int b) {
        a = head(a), b = head(b);
        if (a != b) {
            data[b] = a;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    if (k == 0) k = 1;

    vector<int64_t> val(n);
    for (int i=0; i<n; i++) {
        cin >> val[i];
    }

    vector<int> owner(n);
    for (int i=0; i<n; i++) {
        cin >> owner[i];
    }

    DSU conn(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (!conn.query(x, y) && owner[x] == 1 && owner[y] == 1) {
            val[conn.head(x)] += val[conn.head(y)];
            conn.merge(x, y);
        }
    }

    set<int> heads;
    for (int i=0; i<n; i++) {
        if (owner[i] == 1) heads.insert(conn.head(i));
    }

    priority_queue<int64_t> top_values;
    for (int i : heads) {
        top_values.push(val[i]);
    }

    int64_t total = 0;
    for (int i=0; !top_values.empty() && i<k; i++) {
        total += top_values.top();
        top_values.pop();
    }

    cout << total << endl;
    return 0;
}