#include <bits/stdc++.h>

using namespace std;

class DSU {
public:
    DSU(int n) : dt(n, -1) {}

    int head(int x) {
        if (dt[x] == -1) return x;
        return dt[x] = head(dt[x]);
    }

    void merge(int x, int y) {
        x = head(x), y = head(y);
        if (x != y) dt[y] = x;
    }

    bool query(int x, int y) {
        return head(x) == head(y);
    }
private:
    vector<int> dt;
};

vector<pair<int, int>> kruskal_recon(vector<tuple<int, int, int>>& borders, int n) {
    sort(borders.begin(), borders.end(), [](const auto& a, const auto& b) {
        return get<2>(a) > get<2>(b);
    });

    vector<pair<int, int>> kru_tree(n, make_pair(-1, -1));
    kru_tree.reserve(2*n-1);
    DSU anc(2*n-1);
    for (const auto& bd : borders) {
        int i = get<0>(bd), j = get<1>(bd), w = get<2>(bd);
        if (anc.query(i, j)) continue;
        int a = kru_tree.size();
        kru_tree.push_back(make_pair(-1, w));
        kru_tree[anc.head(i)].first = kru_tree[anc.head(j)].first = a;
        anc.merge(a, i);
        anc.merge(a, j);
    }

    return kru_tree;
}

int lca(vector<pair<int, int>>& par_tree, int a, int b) {
    int n = par_tree.size();
    bool vis[n];
    for (int i=0; i<n; i++) vis[i] = false;
    
    while (a != -1) {
        vis[a] = true;
        a = par_tree[a].first;
    }
    while (b != -1) {
        if (vis[b]) return b;
        vis[b] = true;
        b = par_tree[b].first;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> borders;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        borders.push_back(make_tuple(x, y, z));
    }

    vector<pair<int, int>> krut = kruskal_recon(borders, n);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int idx = lca(krut, x, y);
        if (idx == -1) {
            cout << -1 << endl;
        } else {
            cout << krut[idx].second << endl;
        }
    }
    return 0;
}