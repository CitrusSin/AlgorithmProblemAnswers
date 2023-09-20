#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

struct vec2i {
    i64 x, y;

    vec2i() : x(0), y(0) {}
    vec2i(i64 x, i64 y) : x(x), y(y) {}

    vec2i operator+(const vec2i& vc2) const {
        return vec2i(x+vc2.x, y+vc2.y);
    }
    vec2i operator-() const {
        return vec2i(-x, -y);
    }
    vec2i operator-(const vec2i& vc2) const {
        return vec2i(x-vc2.x, y-vc2.y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<map<int, vec2i>> graph(n);
    bool flag = true;
    while (m--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        vec2i u(x, y);
        graph[a][b] = u;
        graph[b][a] = -u;
    }

    vector<optional<vec2i>> poses(n);
    poses[0] = vec2i(0, 0);

    queue<int> bfsq;
    bfsq.push(0);
    while (!bfsq.empty()) {
        int nd = bfsq.front();
        bfsq.pop();
        for (const pair<int, vec2i>& conn : graph[nd]) {
            if (!poses[conn.first].has_value()) {
                poses[conn.first] = poses[nd].value() + conn.second;
                bfsq.push(conn.first);
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (poses[i].has_value()) {
            vec2i vc = poses[i].value();
            cout << vc.x << ' ' << vc.y << endl;
        } else {
            cout << "undecidable" << endl;
        }
    }
    return 0;
}