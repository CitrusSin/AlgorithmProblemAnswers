#include <bits/stdc++.h>

using namespace std;

pair<int, int> get_interval(const vector<int64_t>& pts, int64_t x, int64_t dist) {
    int left = lower_bound(pts.begin(), pts.end(), x - dist) - pts.begin();
    int right = upper_bound(pts.begin(), pts.end(), x + dist) - pts.begin();

    return make_pair(left, right);
}

int64_t get_rank(const vector<int64_t>& pts, int64_t x, int k) {
    int64_t max_dist = max(abs(pts.back() - x), abs(pts.front() - x));
    int64_t min_dist = 0;

    pair<int, int> interval;
    while (max_dist > min_dist) {
        int64_t dist = min_dist + (max_dist - min_dist) / 2;
        interval = get_interval(pts, x, dist);
        int len = interval.second - interval.first;

        if (len > k) {
            max_dist = dist;
        } else if (len < k) {
            min_dist = dist + 1;
        } else {
            break;
        }
    }
    if (max_dist == min_dist) interval = get_interval(pts, x, max_dist);

    //interval = get_interval(pts, x, max_dist);
    int64_t d1 = abs(pts[interval.first] - x);
    int64_t d2 = abs(pts[interval.second - 1] - x);
    return max(d1, d2);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int64_t>> arr(n);
    for (int i=0; i<n; i++) {
        arr[i].first = i;
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](auto a, auto b){return a.second < b.second;});
    
    vector<int64_t> pts(n), idx(n);
    for (int i=0; i<n; i++) {
        pts[i] = arr[i].second;
        idx[i] = arr[i].first;
    }
    while (q--) {
        int64_t x, k;
        cin >> x >> k;

        int64_t d = get_rank(pts, x, k);
        cout << d << '\n';
    }

    return 0;
}