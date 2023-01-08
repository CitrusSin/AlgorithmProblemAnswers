#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Not thread safe
ll shortest_path(int n, const vector<vector<bool>> &adjacent_table, const vector<int> &machine_speed, int s, int t) {
    static vector<int> unavailable_nodes;
    if (s == t) {
        return 0;
    }

    // Dijkstra

    unavailable_nodes.push_back(s);

    //vector<int> available_nodes;

    map<int, ll> undiscovered;
    map<int, ll> discovered;
    for (int i=0; i<n; i++) {
        bool available = find(unavailable_nodes.begin(), unavailable_nodes.end(), i)==unavailable_nodes.end();
        if (available) {
            if (adjacent_table[s][i]) {
                undiscovered[i] = machine_speed[i];
            } else {
                undiscovered[i] = -1;
            }
            //available_nodes.push_back(i);
        }
    }

    while (undiscovered.size() > 0) {
        int min_node = -1;
        ll min_distance = -1;
        for (const pair<int, ll> &p : undiscovered) {
            if (p.second > 0 && (p.second < min_distance || min_node < 0)) {
                min_node = p.first;
                min_distance = p.second;
            }
        }

        if (min_node == -1) return -1;
        
        discovered[min_node] = min_distance;
        undiscovered.erase(min_node);

        if (min_node == t) break;

        for (pair<const int, ll> &p : undiscovered) {
            ll s2 = shortest_path(n, adjacent_table, machine_speed, min_node, p.first);
            if (s2 >= 0) {
                s2 += min_distance;
                if (s2 < p.second || p.second < 0) {
                    p.second = s2;
                }
            }
        }
    }
    unavailable_nodes.pop_back();
    return discovered[t];
}

int main() {
    int n, q, k;
    cin >> n >> q >> k;
    
    vector<int> machine_speed(n);
    for (int i=0; i<n; i++) {
        cin >> machine_speed[i];
    }

    vector<vector<bool>> adjacent_table(n, vector<bool>(n, false));
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjacent_table[a][b] = true;
        adjacent_table[b][a] = true;
    }

    for (int r=0; r<q; r++) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        ll sp = shortest_path(n, adjacent_table, machine_speed, s, t);
        sp += machine_speed[s];
        cout << sp << endl;
    }
    return 0;
}