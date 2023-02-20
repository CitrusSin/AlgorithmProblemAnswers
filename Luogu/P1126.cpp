#include <bits/stdc++.h>
using namespace std;

struct vec2i {
    int x;
    int y;
    vec2i(int x = 0, int y = 0) : x(x), y(y) {}
    inline vec2i operator+(const vec2i& n) const {
        return vec2i(x+n.x, y+n.y);
    }
    inline vec2i operator-() const {
        return vec2i(-x, -y);
    }
    inline vec2i operator-(const vec2i& n) const {
        return (*this) + (-n);
    }
    inline vec2i operator*(int val) const {
        return vec2i(x*val, y*val);
    }
    inline int operator*(const vec2i& n) const {
        return x*n.x+y*n.y;
    }
    inline bool operator==(const vec2i& n) const {
        return x==n.x && y==n.y;
    }
};

struct state {
    vec2i pos;
    int orientation;
    state(vec2i pos, int ori) : pos(pos), orientation(ori) {}
    vec2i forward_vec() const {
        switch (orientation) {
        case 0:
            return vec2i(0, 1);
        case 1:
            return vec2i(-1, 0);
        case 2:
            return vec2i(0, -1);
        case 3:
            return vec2i(1, 0);
        }
        return vec2i(0, 0);
    }
};

constexpr bool in_bound(const vec2i& v, int n, int m) {
    return v.x > 0 && v.x < n-1 && v.y > 0 && v.y < m-1;
}

int bfs(const vector< vector<char> >& map, vec2i start, vec2i dest, int ori) {
    size_t n = map.size(), m = map[0].size();
    vector<vector<array<bool, 4>>> flag(n, vector< array<bool, 4> >(m, {0}));
    flag[start.x][start.y][ori] = true;
    queue<state> bfsq;
    bfsq.emplace(start, ori);
    size_t cnt = 0;
    while (!bfsq.empty()) {
        size_t size = bfsq.size();
        while (size--) {
            state s = bfsq.front();
            bfsq.pop();
            if (s.pos == dest) {
                return cnt;
            }
            vec2i front = s.forward_vec();
            for (int mul=1; mul<=3; mul++) {
                vec2i new_pos = s.pos + front*mul;
                if (in_bound(new_pos, n, m) && !map[new_pos.x][new_pos.y]) {
                    if (!flag[new_pos.x][new_pos.y][s.orientation]) {
                        bfsq.emplace(new_pos, s.orientation);
                        flag[new_pos.x][new_pos.y][s.orientation] = true;
                    }
                } else break;
            }
            int o1 = (s.orientation+5)%4, o2 = (s.orientation+3)%4;
            if (!flag[s.pos.x][s.pos.y][o1]) {
                bfsq.emplace(s.pos, o1);
                flag[s.pos.x][s.pos.y][o1] = true;
            }
            if (!flag[s.pos.x][s.pos.y][o2]) {
                bfsq.emplace(s.pos, o2);
                flag[s.pos.x][s.pos.y][o2] = true;
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    n++, m++;
    vector< vector<char> > map(n, vector<char>(m, 0));
    bool empty = true;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            int k;
            cin >> k;
            if (k) {
                map[i][j] = map[i+1][j] = map[i][j+1] = map[i+1][j+1] = 1;
                empty = false;
            }
        }
    }
    vec2i start, dest;
    cin >> start.x >> start.y;
    cin >> dest.x >> dest.y;

    while (cin.peek() == ' ') cin.get();
    char orc = cin.get();
    int ori;

    switch (orc) {
    case 'E':
        ori=0;
        break;
    case 'N':
        ori=1;
        break;
    case 'W':
        ori=2;
        break;
    case 'S':
        ori=3;
        break;
    default:
        return 0;    
    }
    if (!empty) {
        cout << bfs(map, start, dest, ori) << endl;
    } else {
        int xd = abs(start.x-dest.x), yd = abs(start.y-dest.y);
        if (xd % 3) xd+=3;
        if (yd % 3) yd+=3;
        xd /= 3;
        yd /= 3;
        vec2i ds = dest-start;
        state st(start, ori);
        int total = 0;
        if (ds*st.forward_vec() < 0) total++;
        total += xd + yd;
        if (xd && yd) total++;
        cout << total << endl;
    }
    return 0;
}