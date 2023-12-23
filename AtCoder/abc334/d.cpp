#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<i64> r(n);
    for (int i=0; i<n; i++) {
        cin >> r[i];
    }

    sort(r.begin(), r.end());
    for (int i=1; i<n; i++) {
        r[i] += r[i-1];
    }

    while (q--) {
        i64 x;
        cin >> x;
        int cnt = upper_bound(r.begin(), r.end(), x) - r.begin();
        cout << cnt << '\n';
    }
    return 0;
}