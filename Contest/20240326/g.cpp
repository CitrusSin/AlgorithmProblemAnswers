#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int64_t> diff(n, 0);

    while (k--) {
        int x, y;
        cin >> x >> y;

        x--, y--;
        int l = y, r = (n-x) + y;

        diff[l]++;
        if (r < n) diff[r]--;
    }

    for (int i=1; i<n; i++) {
        diff[i] += diff[i-1];
    }

    for (int i=0; i<n; i++) {
        diff[i] = diff[i] != 0;
    }

    int64_t tct = 0, ans = 0;
    for (int i=0; i<n; i++) {
        if (!diff[i]) {
            //1, 3, 6
            // n*(n+1)/2
            int64_t uc = tct * (tct + 1) / 2;
            ans += uc;
            tct = 0;
        } else {
            tct++;
        }
    }
    if (tct) ans += tct * (tct + 1) / 2;

    cout << ans << '\n';
}