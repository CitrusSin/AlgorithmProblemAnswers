#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int m[N][N], rec[N][N];

int dfs(int x, int y, int r, int c) {
    const int offset_x[4] = {-1, 0, 1, 0};
    const int offset_y[4] = {0, -1, 0, 1};

    if (rec[x][y] != 0) return rec[x][y];

    int res = 1;
    rec[x][y] = 1;
    for (int d=0; d<4; d++) {
        int nx = x + offset_x[d];
        int ny = y + offset_y[d];
        if (nx < 0 || nx >= r || ny < 0 || ny >= r) continue;
        if (m[nx][ny] >= m[x][y]) continue;
        res = max(res, dfs(nx, ny, r, c)+1);
    }
    rec[x][y] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin >> r >> c;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> m[i][j];
        }
    }

    int max_val = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            max_val = max(max_val, dfs(i, j, r, c));
        }
    }
    cout << max_val << endl;

    return 0;
}