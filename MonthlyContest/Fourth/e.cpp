#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool intersect(const pair<double, double>& a, const pair<double, double>& b, pair<double, double>& c) {
    double l = max(a.first, b.first);
    double r = min(a.second, b.second);
    if (l <= r) {
        c.first = l;
        c.second = r;
        return true;
    } else {
        return false;
    }
}

bool pair_first_comparator(const pair<double, double>& a, const pair<double, double>& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    int case_cnt = 1;
    while (n != 0 || d != 0) {
        vector< pair<double, double> > ranges;
        ranges.reserve(n);
        bool fail_sign = false;
        for (int i=0; i<n; i++) {
            double x, y;
            cin >> x >> y;

            if (y > d) {
                fail_sign = true;
                break;
            }

            double hl = sqrt(d*d-y*y);
            ranges.push_back(make_pair(x-hl, x+hl));
        }

        if (fail_sign) {
            cout << "Case " << case_cnt++ << ": " << -1 << endl;
            cin >> n >> d;
            continue;
        }

        sort(ranges.begin(), ranges.end(), pair_first_comparator);

        pair<double, double> rn = ranges.front();
        int cnt = 1;
        for (int i=1; i<n; i++) {
            if (!intersect(ranges[i], rn, rn)) {
                cnt++;
                rn = ranges[i];
            }
        }

        cout << "Case " << case_cnt++ << ": " << cnt << endl;
        cin >> n >> d;
    }
    return 0;
}