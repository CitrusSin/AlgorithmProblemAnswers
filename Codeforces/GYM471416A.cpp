#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n, k;
    cin >> n >> k;

    map<int64_t, int64_t> reqs;
    for (int64_t i=0; i<n; i++) {
        int64_t a, b;
        cin >> a >> b;
        reqs[a] += b;
    }

    int64_t nd = 0;
    int64_t pd = 0;
    for (const pair<int64_t, int64_t>& p : reqs) {
        pd += (p.first - nd) * k;
        nd = p.first;
        if (pd < p.second) {
            cout << "No" << endl;
            return;
        }
        pd -= p.second;
    }
    cout << "Yes" << endl;
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