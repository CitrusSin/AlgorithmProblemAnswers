#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> seat_requires;
    int left_count = 0, right_count = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (p == -1) {
            left_count++;
        } else if (p == -2) {
            right_count++;
        } else {
            if (p <= m) seat_requires.push_back(p-1);
        }
    }

    int result = 0;
    sort(seat_requires.begin(), seat_requires.end());
    auto last_it = unique(seat_requires.begin(), seat_requires.end());
    seat_requires.erase(last_it, seat_requires.end());
    for (int i=0; i<seat_requires.size(); i++) {
        int lcp = i + left_count, rcp = seat_requires.size()-i-1 + right_count;
        int lcs = seat_requires[i], rcs = m-seat_requires[i]-1;
        int total = min(lcp, lcs) + min(rcp, rcs) + 1;
        result = max(result, total);
    }
    result = max(result, min(m, left_count+int(seat_requires.size())));
    result = max(result, min(m, right_count+int(seat_requires.size())));
    cout << result << endl;
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