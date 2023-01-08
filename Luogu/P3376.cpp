#include <bits/stdc++.h>

using namespace std;

struct side {
    int origin;
    int target;
    int flow;
};

int max_flow_ek_dfs(vector<vector<side>> &map, set<int> &searched_node, int s, int t, int current_flow, vector<side*> &passed_sides, vector<side*> &reverse_sides) {
    if (s == t) {
        int size = passed_sides.size();
        for (int i=0; i<size; i++) {
            passed_sides[i]->flow += current_flow;
        }
    }
}

int max_flow_ek(const vector<vector<side>> &map_origin, int s, int t) {
    vector<vector<side>> map = map_origin; // Copy
    int n = map.size();
    // Add inverse side
    for (int i=0; i<n; i++) {
        vector<side> &sides = map[i];
        for (side &si : sides) {
            // Search for inverse side
            bool has_inv_side = false;
            for (side &si2 : map[si.target]) {
                if (si2.target == si.origin) {
                    has_inv_side = true;
                    break;
                }
            }

            if (!has_inv_side) {
                map[si.target].emplace_back(side{si.target, si.origin, 0});
            }
        }
    }

    // dfs
    int flow_accumulator = 0;

}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<side>> map(n);
    for (int i=0; i<m; i++) {
        int b, e, f;
        cin >> b >> e >> f;
        b--;
        e--;
        map[b].emplace_back(side{b, e, f});
    }


    return 0;
}