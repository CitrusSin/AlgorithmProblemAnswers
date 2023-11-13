#include <bits/stdc++.h>
using namespace std;

bool pair_comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> posis(n), radii(n);
    for (int i=0; i<n; i++) {
        cin >> posis[i];
    }
    for (int i=0; i<n; i++) {
        cin >> radii[i];
    }

    vector<pair<int, int>> ranges;
    ranges.reserve(n);

    for (int i=0; i<n; i++) {
        ranges.emplace_back(posis[i]-radii[i], posis[i]+radii[i]);
    }

    sort(ranges.begin(), ranges.end(), pair_comparator);
    int cnt = 1;
    int a = ranges[0].first, b = ranges[0].second;
    for (int i=1; i<n; i++) {
        pair<int, int>& r = ranges[i];
        if (r.first > b) {
            a = r.first;
            b = r.second;
            cnt++;
        } else {
            b = max(b, r.second);
        }
    }
    cout << cnt << endl;
    return 0;
}