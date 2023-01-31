#include <bits/stdc++.h>
using namespace std;

constexpr bool pos_in_bound(int x, int y, int n, int m) {
    return x>=0 && x<n && y>=0 && y<m;
}

constexpr int clamp(int x, int b) {
    return x>=0 ? x%b : (b-(-x)%b)%b;
}

bool process_matrix(const vector< vector<char> >& mat) {
    static const int offset_x[4] = {-1, 0, 0, 1};
    static const int offset_y[4] = {0, -1, 1, 0};

    if (mat.size() == 0) return false;
    size_t n = mat.size(), m = mat[0].size();
    
    int bx = -1, by = -1;
    for (int i=0; i<n && bx<0; i++) {
        for (int j=0; j<m && bx<0; j++) {
            if (mat[i][j] == 'S') {
                bx = i;
                by = j;
            }
        }
    }

    vector< vector<char> > flag(n, vector<char>(m, 0));
    queue< pair<int, int> > bfsq;
    bfsq.emplace(bx, by);
    while (!bfsq.empty()) {
        size_t s = bfsq.size();
        while (s--) {
            pair<int, int> pos = bfsq.front();
            bfsq.pop();

            flag[pos.first][pos.second] = 1;

            for (int d=0; d<4; d++) {
                int x2 = pos.first + offset_x[d];
                int y2 = pos.second + offset_y[d];

                x2 = clamp(x2, n);
                y2 = clamp(y2, m);
                
                if (mat[x2][y2] != '#' && !flag[x2][y2]) {
                    bfsq.emplace(x2, y2);
                }
            }
        }
    }
    
    // Detect border
    for (int i = 1; i<m-1; i++) {
        if (flag[0][i] && flag[n-1][i]) {
            return true;
        }
    }
    for (int i = 1; i<n-1; i++) {
        if (flag[i][0] && flag[i][m-1]) {
            return true;
        }
    }
    return flag[0][0]&&flag[n-1][0] || flag[n-1][0]&&flag[n-1][m-1] || flag[n-1][m-1]&&flag[0][m-1] || flag[0][m-1]&&flag[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string begin_line;
    while (getline(cin, begin_line), !begin_line.empty() && cin) {
        stringstream sstr(begin_line);

        int n, m;
        sstr >> n >> m;

        vector< vector<char> > mat;
        mat.reserve(n);
        for (int i=0; i<n; i++) {
            string line;
            getline(cin, line);

            if (line.back() == '\r') line.pop_back();
            mat.emplace_back(line.begin(), line.end());
        }

        cout << (process_matrix(mat)?"Yes":"No") << endl;
    }
    return 0;
}