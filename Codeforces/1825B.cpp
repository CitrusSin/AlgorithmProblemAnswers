#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

void solve() {
    int n, m;
    cin >> n >> m;

    int len = n*m;
    int arr[len];
    for (int i=0; i < len; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+len);

    u64 d1 = arr[len-1]-arr[0];
    u64 d2 = arr[len-2]-arr[0];
    u64 d3 = arr[len-1]-arr[1];
    if (d2 < d3) swap(d2, d3);

    u64 total = 0;
    total += d1 * (max(n, m)-1)*min(n, m);
    total += d2 * (min(n, m)-1);

    cout << total << endl;
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