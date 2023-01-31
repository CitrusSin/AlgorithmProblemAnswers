#include <bits/stdc++.h>
using namespace std;

const size_t N = 1000;
bool square[N][N], mark[N][N];
int result_data[N][N];

const int offset_x[4] = {1, 0, 0, -1};
const int offset_y[4] = {0, 1, -1, 0};

template <size_t P, size_t Q>
int fill_area(const bool (*square_ptr)[P][Q], bool (*mark_ptr)[P][Q], int n, int x, int y) {
    (*mark_ptr)[x][y] = true;
    int area = 1;
    for (int d=0; d<4; d++) {
        int x2 = x+offset_x[d];
        int y2 = y+offset_y[d];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || (*mark_ptr)[x2][y2] || (*square_ptr)[x][y] == (*square_ptr)[x2][y2]) {
            continue;
        }
        area += fill_area(square_ptr, mark_ptr, n, x2, y2);
    }
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string first_line;
    getline(cin, first_line);
    stringstream flss(first_line);

    int n, m;
    flss >> n >> m;
    
    for (int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        for (int j=0; j<n; j++) {
            square[i][j] = line[j] == '1';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (result_data[i][j] != 0) {
                continue;
            }
            memset(mark, 0, sizeof(mark));
            int area = fill_area(&square, &mark, n, i, j);
            
            queue< pair<int, int> > bfsq;
            bfsq.emplace(i, j);
            result_data[i][j] = area;
            while (!bfsq.empty()) {
                int s = bfsq.size();
                while (s--) {
                    pair<int, int> pos = bfsq.front();
                    bfsq.pop();

                    for (int d=0; d<4; d++) {
                        int x2 = pos.first+offset_x[d];
                        int y2 = pos.second+offset_y[d];
                        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || !mark[x2][y2] || result_data[x2][y2]) {
                            continue;
                        }
                        result_data[x2][y2] = area;
                        bfsq.emplace(x2, y2);
                    }
                }
            }
        }
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << result_data[x][y] << endl;
    }
    return 0;
}