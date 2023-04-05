#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 t;
    cin >> t;
    while (t--) {
        u64 n, c, d;
        cin >> n >> c >> d;

        set<int> s;
        u64 cost = 0;
        for (u64 i=0; i<n; i++) {
            int p;
            cin >> p;
            if (s.count(p)) {
                cost += c;
            } else {
                s.insert(p);
            }
        }

        u64 min_add_cost = numeric_limits<u64>::max();
        u64 n2 = s.size(), cnt = 1;
        for (int p : s) {
            min_add_cost = min(min_add_cost, (n2-cnt)*c + (p-cnt)*d);
            cnt++;
        }

        u64 res = cost + min_add_cost;
        res = min(res, n*c+d);
        cout << res << endl;
    }
    return 0;
}