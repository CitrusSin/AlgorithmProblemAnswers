#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 count_permu(vector<int>& v) {
    size_t n = v.size();
    size_t m = n-1;
    sort(v.begin(), v.end());

    vector<u64> dif(m);
    for (int i=1; i<n; i++) {
        dif[i-1] = v[i] - v[i-1];
    }

    size_t a = 1, b = m;
    u64 total = 0;
    for (int i=0; i<m; i++) {
        total += dif[i] * (a++)*(b--);
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arrs(m, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> arrs[j][i];
            }
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        u64 total = 0;
        for (vector<int>& vec : arrs) {
            total += count_permu(vec);
        }
        cout << total << endl;
    }
    return 0;
}