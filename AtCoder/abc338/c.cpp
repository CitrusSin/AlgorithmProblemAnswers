#include <bits/stdc++.h>
#include <limits>

using namespace std;

// x a_i + y b_i <= q_i
// x >= 0
// y >= 0

int main() {
    int n;
    cin >> n;

    vector<int> q(n), a(n), b(n);
    for (int i=0; i<n; i++) cin >> q[i];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    auto dt = [&](int x, int y) {
        if (x < 0 || y < 0) return false;
        for (int i=0; i<n; i++) {
            if (1ll * x * a[i] + 1ll * y * b[i] > q[i]) return false;
        }
        return true;
    };

    int max_x = numeric_limits<int>::max(), max_y = numeric_limits<int>::max();
    for (int i=0; i<n; i++) {
        if (a[i]) max_x = min(max_x, q[i] / a[i]);
        if (b[i]) max_y = min(max_y, q[i] / b[i]);
    }

    int max_val = 0;
    int y = max_y;
    for (int x=0; x<=max_x; x++) {
        while (!dt(x, y)) y--;
        max_val = max(max_val, x+y);
    }

    cout << max_val << endl;
    return 0;
}