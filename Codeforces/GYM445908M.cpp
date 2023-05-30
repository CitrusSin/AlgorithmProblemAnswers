#include <bits/stdc++.h>

using namespace std;

struct point {
    int64_t x;
    int64_t y;

    point(int64_t x, int64_t y) : x(x), y(y) {}

    int64_t sqd(const point& p2) const {
        return (x-p2.x)*(x-p2.x) + (y-p2.y)*(y-p2.y);
    }

    static bool lined(const point& p1, const point& p2, const point& p3) {
        int64_t x1 = p2.x-p1.x, y1 = p2.y-p1.y;
        int64_t x2 = p3.x-p2.x, y2 = p3.y-p2.y;
        return x1*y2 == x2*y1;
    }
};

int64_t get_d(const vector<point>& pts, int b, int e) {
    int n = e-b;
    int bp = b, lp = -1;
    int64_t dst = 0;
    int qp = -1;
    for (;;) {
        for (int i=0; i<n; i++) {
            int idx = (i%n)+b;
            if (idx == bp) continue;
            int64_t nd = pts[idx].sqd(pts[bp]);
            if (nd >= dst) {
                qp = idx;
                dst = nd;
            }
        }
        if (qp == lp) {
            return dst;
        } else {
            lp = bp;
            swap(bp, qp);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<point> points;
    for (int i=0; i<n; i++) {
        int64_t x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    // Double len
    for (int i=0; i<n; i++) {
        points.push_back(points[i]);
    }

    int64_t min_val = numeric_limits<int64_t>::max();
    
    for (int i=0; i<n; i++) {
        for (int j=i+2; j<n; j++) {
            if (i == 0 && j == n-1) continue;
            if (!point::lined(points[i], points[j-1], points[j])) {
                if (i == 2 && j == 4) {
                    cout << 't' << endl;
                }
                int64_t d1 = get_d(points, i, j+1);
                int64_t d2 = get_d(points, j, n+i+1);
                min_val = min(min_val, d1+d2);
            }
        }
    }

    cout << min_val << endl;
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