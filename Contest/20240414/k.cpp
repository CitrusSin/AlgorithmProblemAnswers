#include <bits/stdc++.h>

using namespace std;

struct node_t {
    int value;
    shared_ptr<node_t> fa;

    node_t(int value) : value(value), fa(nullptr) {}
};

shared_ptr<node_t> dsu_head(shared_ptr<node_t> n) {
    if (n->fa == nullptr) {
        return n;
    }

    return n->fa = dsu_head(n->fa);
}

void solve() {
    unordered_map<int, shared_ptr<node_t>> node_query;

    node_query.insert(make_pair(0, make_shared<node_t>(0)));

    int n, q;
    cin >> n >> q;
    vector<shared_ptr<node_t>> ind(n, node_query[0]);

    while (q--) {
        int op, x;
        cin >> op >> x;

        if (op == 1) {
            x--;
            ind[x] = dsu_head(ind[x]);
            int value = ind[x]->value;
            value++;
            if (node_query.count(value)) {
                ind[x] = node_query[value];
            } else {
                node_query[value] = ind[x] = make_shared<node_t>(value);
            }
        } else if (op == 2 && node_query.count(x)) {
            shared_ptr<node_t> node = node_query[x];
            node_query.erase(x);

            node->value++;
            if (node_query.count(node->value)) {
                node->fa = node_query[node->value];
            } else {
                node_query[node->value] = node;
            }
        }
    }

    for (int i=0; i<n; i++) {
        ind[i] = dsu_head(ind[i]);
        if (i) cout << ' ';
        cout << ind[i]->value;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}