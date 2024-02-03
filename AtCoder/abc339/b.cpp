#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>> mp(h, vector<char>(w, '.'));

    const array<int, 4> dy{0, 1, 0, -1}, dx{-1, 0, 1, 0};
    int x = 0, y = 0, ori = 0;

    for (int i=0; i<n; i++) {
        if (mp[x][y] == '.') {
            mp[x][y] = '#';
            ori = (ori + 1) % 4;
        } else {
            mp[x][y] = '.';
            ori = (ori + 3) % 4;
        }
        x += dx[ori];
        y += dy[ori];
        x = (x + h) % h;
        y = (y + w) % w;
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}