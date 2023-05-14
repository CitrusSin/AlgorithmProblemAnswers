#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<u64> pfs(n);
    pfs[0] = arr[0];
    for (int i=1; i<n; i++) {
        pfs[i] = pfs[i-1] + arr[i];
    }

    int l=-1, r=n-1-k;
    u64 max_sum = 0;
    while (l < r && r < n) {
        u64 pt = pfs[r];
        if (l >= 0) pt -= pfs[l];
        max_sum = max(max_sum, pt);
        r += 1;
        l += 2;
    }
    cout << max_sum << endl;
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