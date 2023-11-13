#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u32 = uint32_t;

constexpr bool pos_in_bound(int x, int y, int n, int m) {
    return x>=0 && x<n && y>=0 && y<m;
}

constexpr int clamp(int x, int b) {
    return x>=0 ? x%b : (b-(-x)%b)%b;
}

u64 compress_position(int x, int y) {
    union {
        struct{
            int px;
            int py;
        };
        u64 val;
    } s;
    s.px = x, s.py = y;
    return s.val;
}

bool dfs(const vector<vector<char>>& mat, unordered_map<u64, bool>& sign, int n, int m, int lx, int ly) {
    static const int offset_x[4] = {-1, 0, 0, 1};
    static const int offset_y[4] = {0, -1, 1, 0};

    for (int d=0; d<4; d++) {
        int lx2 = lx+offset_x[d], ly2 = ly+offset_y[d];
        int x2 = clamp(lx2, n), y2 = clamp(ly2, m);

        u64 comp_pos = compress_position(lx2, ly2);
        u64 origin_pos = compress_position(x2, y2);

        if (lx2 == x2 && ly2 == y2) {
            if (!sign[comp_pos] && mat[x2][y2]) {
                sign[comp_pos] = true;
                bool res = dfs(mat, sign, n, m, lx2, ly2);
                if (res) return true;
            }
        } else if (mat[x2][y2]) {
            if (sign[origin_pos]) return true;
            if (!sign[comp_pos]) {
                sign[comp_pos] = true;
                bool res = dfs(mat, sign, n, m, lx2, ly2);
                if (res) return true;
            }
        }
    }
    return false;
}

bool process_matrix(const vector< vector<char> >& mat, int x, int y) {
    size_t n = mat.size(), m = mat[0].size();
    unordered_map<u64, bool> sign;
    sign[compress_position(x, y)] = true;
    return dfs(mat, sign, n, m, x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string begin_line;
    while (!cin.eof()) {
        getline(cin, begin_line);

        if (begin_line.back() == '\r') begin_line.pop_back();
        if (begin_line.empty()) break;

        stringstream sstr(begin_line);

        int n, m;
        sstr >> n >> m;

        vector< vector<char> > mat(n, vector<char>(m, false));
        int sx = 0, sy = 0;
        for (int i=0; i<n; i++) {
            string line;
            cin >> line;
            while (cin.peek() == '\r' || cin.peek() == '\n') cin.get();

            for (int j=0; j<m; j++) {
                switch (line[j]) {
                    case 'S':
                        sx = i;
                        sy = j;
                    case '.':
                        mat[i][j] = true;
                        break;
                    case '#':
                        mat[i][j] = false;
                        break;
                }
            }
        }

        cout << (process_matrix(mat, sx, sy)?"Yes":"No") << endl;
    }
    return 0;
}