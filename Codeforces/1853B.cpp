#include <bits/stdc++.h>

using namespace std;

int detect_len(int r0, int r1) {
    int len = 2;
    while (r0 >= r1 && r0 >= 0 && r1 >= 0) {
        len++;
        int r2 = r0-r1;
        r0 = r1;
        r1 = r2;
    }

    return --len;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for (int i=0; i<=n; i++) {
        int len = detect_len(n, i);
        if (len >= k) {
            cnt++;
        }
    }

    cout << cnt << endl;
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