#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

template <typename T>
using upq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void solve() {
    int k;
    cin >> k;

    vector<vector<int>> sets(k);
    for (int i=0; i<k; i++) {
        int c;
        cin >> c;
        while (c--) {
            int v;
            cin >> v;
            sets[i].push_back(v);
        }
        sort(sets[i].begin(), sets[i].end());
    }

    vector<int> ptrs(k, 0);

    struct node_t {
        int idx;
        int val;
        node_t(int idx, int val) : idx(idx), val(val) {}
        bool operator>(const node_t& n2) const {
            return val > n2.val;
        }
    };

    upq<node_t> nodes;
    upq<int> complete_nodes;

    for (int i=0; i<k; i++) {
        nodes.emplace(i, sets[i][ptrs[i]]);
    }
    
    int min_val = numeric_limits<int>::max(), max_val = numeric_limits<int>::min();
    for (int i=0; i<k; i++) {
        min_val = min(min_val, sets[i][ptrs[i]]);
        max_val = max(max_val, sets[i][ptrs[i]]);
    }

    int md = max_val - min_val;

    while (!nodes.empty()) {
        node_t nd = nodes.top();
        nodes.pop();

        if (ptrs[nd.idx] + 1 == sets[nd.idx].size()) {
            complete_nodes.push(nd.val);
            continue;
        }

        nd.val = sets[nd.idx][++ptrs[nd.idx]];
        int new_min = nd.val;
        if (!complete_nodes.empty()) new_min = min(new_min, complete_nodes.top());
        if (!nodes.empty()) new_min = min(new_min, nodes.top().val);

        if (nd.val > max_val) max_val = nd.val;
        min_val = new_min;

        md = min(md, max_val - min_val);

        if (ptrs[nd.idx] + 1 == sets[nd.idx].size()) {
            complete_nodes.push(nd.val);
        } else {
            nodes.push(nd);
        }
    }

    cout << md << '\n';
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
    cout << flush;
    return 0;
}