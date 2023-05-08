#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 vol(const vector<vector<int>>& depths, vector<vector<char>>& vis, int x, int y) {
    const int ox[4] = {1, 0, 0, -1}, oy[4] = {0, -1, 1, 0};
    int n = depths.size(), m = depths[0].size();

    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (vis[x][y] || depths[x][y] == 0) return 0;
    vis[x][y] = true;
    i64 v = depths[x][y];
    for (int d=0; d<4; d++) {
        int x2 = x+ox[d], y2 = y+oy[d];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) continue;
        if (vis[x2][y2] || depths[x2][y2] == 0) continue;
        v += vol(depths, vis, x2, y2);
    }
    return v;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> depths(n, vector<int>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> depths[i][j];
        }
    }

    vector<vector<char>> mark(n, vector<char>(m, false));

    i64 max_vol = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (depths[i][j] != 0 && !mark[i][j]) {
                max_vol = max(max_vol, vol(depths, mark, i, j));
            }
        }
    }

    cout << max_vol << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}