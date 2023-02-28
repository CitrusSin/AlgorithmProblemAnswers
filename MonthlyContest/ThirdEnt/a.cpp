#include <bits/stdc++.h>
using namespace std;

bool space[100][100];

const int offset_x[4] = {0, 1, 0, -1};
const int offset_y[4] = {1, 0, -1, 0};

int count_clear_region(int x, int y, int n, int m) {
    if (space[x][y]) {
        int counter = 1;
        space[x][y] = false;
        for (int d=0; d<4; d++) {
            int x2 = x+offset_x[d];
            int y2 = y+offset_y[d];
            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                counter += count_clear_region(x2, y2, n, m);
            }
        }
        return counter;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            space[i][j] = false;
        }
    }

    while (k--) {
        int r, c;
        cin >> r >> c;
        space[--r][--c] = true;
    }

    int max_count = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (space[i][j]) {
                int count = count_clear_region(i, j, n, m);
                if (count > max_count) max_count = count;
            }
        }
    }
    cout << max_count << endl;;
    return 0;
}