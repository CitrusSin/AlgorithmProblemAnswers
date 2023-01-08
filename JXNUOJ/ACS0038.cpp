#include <bits/stdc++.h>

using namespace std;

class graph {
public:
    graph() = default;

    void connect(int u, int v) {
        set<int> &up = g[u];
        auto iter = up.find(v);
        if (iter == up.end()) {
            up.insert(v);
            g[v].insert(u);
        }
    };

    unsigned int distance(int u, int v) const {
        queue<int> bfs_queue;
        bfs_queue.push(u);
        
        unsigned int counter = 0;
        set<int> searched;
        while (true) {
            size_t s = bfs_queue.size();
            if (s == 0) {
                return -1;
            }
            for (size_t i=0; i<s; i++) {
                int val = bfs_queue.front();
                bfs_queue.pop();
                searched.insert(val);

                if (val == v) {
                    return counter;
                }

                auto it = g.find(val);
                if (it == g.end()) {
                    continue;
                }
                const set<int> &st = it->second;
                for (int q : st) {
                    auto i2 = searched.find(q);
                    if (i2 == searched.end()) {
                        bfs_queue.push(q);
                    }
                }
            }
            counter++;
        }
    };
private:
    map<int, set<int>> g;
};

struct castle {
    int id;
    int count;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, e;
    cin >> n >> m >> k >> e;

    castle castles[n];
    for (int i=0; i<n; i++) {
        castles[i].id = i+1;
        castles[i].count = 0;
    }

    for (int i=0; i<m; i++) {
        int id;
        cin >> id;

        castles[id-1].count++;
    }

    graph roadmap;
    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        roadmap.connect(u, v);
    }

    sort(castles, castles+n, [](castle &a, castle &b) {return a.count > b.count;});

    int baseid = castles[0].id;

    sort(castles+1, castles+n, [&roadmap, baseid](castle &a, castle &b) {
        return roadmap.distance(baseid, a.id) < roadmap.distance(baseid, b.id);
    });

    int total_count = castles[0].count;
    int max_distance = 0;
    for (int c=1; c<n; c++) {
        if (total_count >= k) break;
        total_count += castles[c].count;
        max_distance = roadmap.distance(baseid, castles[c].id);
    }

    if (total_count < k) {
        cout << "-1" << endl;
    } else {
        cout << max_distance << endl;
    }
    return 0;
}