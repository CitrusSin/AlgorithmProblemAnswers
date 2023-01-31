#include <bits/stdc++.h>
using namespace std;

constexpr pair<int, int> char_direction(char c) {
    switch (c) {
    case 'U':
        return {0, 1};
    case 'D':
        return {0, -1};
    case 'L':
        return {-1, 0};
    case 'R':
        return {1, 0};
    }
    return {0, 0};
}
const pair<int, int> directions[4] = {char_direction('U'), char_direction('D'), char_direction('L'), char_direction('R')};

bool check_path(const string& path) {
    size_t n = path.size();

    bool square[201][201];
    int x = 100, y = 100;
    square[x][y] = true;
    for (char c : path) {
        pair<int, int> d = char_direction(c);
        x += d.first, y += d.second;
        if (square[x][y]) return false;
        square[x][y] = true;

        pair<int, int> inv = {-d.first, -d.second};
        for (const pair<int, int>& d2 : directions) {
            if (d2 != inv) {
                int x3 = x+d2.first, y3 = y+d2.second;
                if (square[x3][y3]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string path;
    cin >> path;

    cout << (check_path(path)?"OK":"BUG") << endl;
    return 0;
}