#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<unordered_set<int>>& forward, vector<char>& mark, int i) {
    if (mark[i]) return;
    mark[i] = true;
    for (int j : forward[i]) {
        dfs(forward, mark, j);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> c(n);
    for (int i=0; i<n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        c[i] = make_tuple(x, y, r);
    }

    sort(c.begin(), c.end(), [](tuple<int, int, int>& a, tuple<int, int, int>& b) {
        return get<0>(a) < get<0>(b);
    });

    vector<int> xs;
    for (auto& x : c) {
        xs.push_back(get<0>(x));
    }

    vector<unordered_set<int>> forward(n);
    for (int i=0; i<n; i++) {
        int x1 = get<0>(c[i]), y1 = get<1>(c[i]);
        int r = get<2>(c[i]);
        int begin_point = lower_bound(xs.begin(), xs.end(), x1-r) - xs.begin();
        for (int j=begin_point; j<n; j++) {
            if (i == j) continue;
            int x2 = get<0>(c[j]), y2 = get<1>(c[j]);
            if (x2-x1 > r) break;
            int sqd = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            if (sqd <= r*r) forward[i].insert(j);
        }
    }

    vector<char> mark(n, false);
    for (int i=0; i<m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        int begin_point = lower_bound(xs.begin(), xs.end(), x-r) - xs.begin();
        for (int j=begin_point; j<n; j++) {
            if (mark[j]) continue;
            int x2 = get<0>(c[j]), y2 = get<1>(c[j]);
            if (x2-x > r) break;
            int sqd = (x-x2)*(x-x2)+(y-y2)*(y-y2);
            if (sqd <= r*r) dfs(forward, mark, i);
        }
    }

    int cnt = accumulate(mark.begin(), mark.end(), 0);
    cout << cnt << endl;
    return 0;
}