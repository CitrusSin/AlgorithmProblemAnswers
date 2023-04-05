#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

constexpr u64 height_max(u64 a, u64 b, u64 n) {
    if (n == 0) return 0;
    return (a-b)*(n-1)+a;
}

constexpr u64 height_min(u64 a, u64 b, u64 n) {
    if (n == 0 || n == 1) {
        return 0;
    } else {
        return height_max(a, b, n-1)+1;
    }
}

constexpr bool in_range(u64 x, u64 l, u64 r) {
    return x >= l && x <= r;
}

constexpr bool range_cross(u64 l1, u64 r1, u64 l2, u64 r2) {
    return l1<=r2 && l2<=r1;
}

u64 estimate_day(u64 h, u64 a, u64 b) {
    if (h < a) return 1;
    u64 step = a-b;
    u64 dayf = (h-a)/step;
    if ((h-a)%step!=0) dayf++;
    dayf++;
    return dayf;
}

void run_query(int q) {
    bool fgx = false;
    u64 hl = 0, hr = numeric_limits<u64>::max();
    while (q--) {
        if (fgx) {
            cout << ' ';
        } else {
            fgx = true;
        }
        int type;
        cin >> type;
        if (type == 1) {
            u64 a, b, n;
            cin >> a >> b >> n;
            u64 hl2 = height_min(a, b, n), hr2 = height_max(a, b, n);
            if (!range_cross(hl2, hr2, hl, hr)) {
                cout << 0;
            } else {
                cout << 1;
                if (in_range(hl2, hl, hr)) {
                    hl = hl2;
                }
                if (in_range(hr2, hl, hr)) {
                    hr = hr2;
                }
            }
        } else if (type == 2) {
            u64 a, b;
            cin >> a >> b;
            u64 d0 = estimate_day(hl, a, b), d1 = estimate_day(hr, a, b);
            if (d0 != d1) {
                cout << -1;
            } else {
                cout << d0;
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        run_query(q);
    }
    return 0;
}