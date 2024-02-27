#include <bits/stdc++.h>

using namespace std;

template <typename T>
pair<T, T> operator+(const pair<T, T>& p1, const pair<T, T>& p2) {
    return pair<T, T>(p1.first + p2.first, p1.second + p2.second);
}

bool check_route(
    const vector<vector<char>>& s,
    const vector<pair<int, int>>& route,
    pair<int, int> point
) {
    int h = s.size(), w = s[0].size();
    for (pair<int, int> p : route) {
        auto p2 = p + point;
        if (p2.first < 0 || p2.first >= h || p2.second < 0 || p2.second >= w) return false;
        if (s[p2.first][p2.second] == '#') return false;
    }
    return true;
}

int main() {
    const array<pair<int, int>, 4> directions = {pair<int, int>{0, -1}, pair<int, int>{0, 1}, pair<int, int>{-1, 0}, pair<int, int>{1, 0}};
    map<char, int> dmap;
    for (int i=0; i<4; i++) {
        dmap["LRUD"[i]] = i;
    }

    int h, w, n;
    cin >> h >> w >> n;

    string t;
    cin >> t;

    vector<pair<int, int>> route(t.size()+1);
    route[0] = pair<int, int>(0, 0);
    for (int i=1; i<=t.size(); i++) {
        route[i] = route[i-1] + directions[dmap[t[i-1]]];
    }

    vector<vector<char>> s(h, vector<char>(w));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> s[i][j];
        }
    }

    int ans = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (check_route(s, route, make_pair(i, j))) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}