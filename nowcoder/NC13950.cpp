#include <bits/stdc++.h>

using namespace std;

int shortest_distance(const vector<vector<bool>> &pth, const set<int> &cities, int capital, int city_count) {
    queue<int> bfs_queue;
    set<int> searched_cities;
    int depth_counter = 0;
    
    bfs_queue.push(capital);
    searched_cities.insert(capital);
    while (bfs_queue.size() > 0) {
        int len = bfs_queue.size();
        for (int i=0; i<len; i++) {
            int c = bfs_queue.front();
            bfs_queue.pop();
            
            if (cities.find(c) != cities.end()) {
                return depth_counter;
            }
            
            for (int j=0; j<city_count; j++) {
                if (searched_cities.find(j) == searched_cities.end() && pth[c][j]) {
                    searched_cities.insert(j);
                    bfs_queue.push(j);
                }
            }
        }
        depth_counter++;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<bool>> pth(n);
    for (int i=0; i<n; i++) {
        pth[i].assign(n, false);
    }
    
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        pth[u][v] = true;
        pth[v][u] = true;
    }
    
    int k;
    cin >> k;
    vector<vector<int>> gangs;
    for (int i=0; i<k; i++) {
        int ci;
        cin >> ci;
        vector<int> gang(ci);
        for (int j=0; j<ci; j++) {
            cin >> gang[j];
            gang[j]--;
        }
        gangs.push_back(gang);
    }
    
    int q;
    cin >> q;
    for (int r=0; r<q; r++) {
        int v, t;
        cin >> v >> t;
        v--;
        set<int> cities;
        for (int i=0; i<t; i++) {
            int g;
            cin >> g;
            g--;
            for (int city : gangs[g]) {
                cities.insert(city);
            }
        }
        
        // bfs
        int d = shortest_distance(pth, cities, v, n);
        cout << d << endl;
    }
    return 0;
}