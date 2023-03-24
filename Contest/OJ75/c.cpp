#include <bits/stdc++.h>
using namespace std;

bool sort_comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, m;
    cin >> l >> m;

    vector<pair<int, int>> ranges;
    ranges.reserve(m);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ranges.emplace_back(a, b);
    }

    sort(ranges.begin(), ranges.end(), sort_comparator);

    int occupied = 0;
    int a=ranges[0].first, b=ranges[0].second;
    for (pair<int, int>& r : ranges) {
        if (r.first > b) {
            occupied += b-a+1;
            a = r.first;
            b = r.second;
        } else {
            b = max(b, r.second);
        }
    }
    occupied += b-a+1;
    cout << (l-occupied+1) << endl;
    return 0;
}