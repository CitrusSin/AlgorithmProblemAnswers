#include <bits/stdc++.h>
using namespace std;

int longest_distance_internal(const vector< vector<int> >& forward_list, int start, set<int>& mark) {
    int n = forward_list.size();
    mark.insert(start);

    int max_dist = 0;
    for (int next = 0; next < n; next++) {
        if (!mark.count(next) && forward_list[start][next] >= 0) {
            int sub_dist = longest_distance_internal(forward_list, next, mark);
            sub_dist += forward_list[start][next];
            max_dist = max(max_dist, sub_dist);
        }
    }
    mark.erase(start);
    return max_dist;
}

int longest_distance(const vector< vector<int> >& forward_list) {
    int n = forward_list.size();

    int max_dist = 0;
    set<int> mark;
    for (int b=0; b<n; b++) {
        int dist = longest_distance_internal(forward_list, b, mark);
        max_dist = max(max_dist, dist);
        mark.clear();
    }

    return max_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > forward_list(n, vector<int>(n, -1));
    while (m--) {
        int x, y, dist;
        cin >> x >> y >> dist;
        x--;
        y--;
        forward_list[x][y] = forward_list[y][x] = dist;
    }
    
    cout << longest_distance(forward_list) << endl;
    return 0;
}