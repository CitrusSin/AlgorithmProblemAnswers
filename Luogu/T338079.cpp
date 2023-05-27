#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, m, k;
    cin >> n >> m >> k;

    vector<i64> p(n);
    for (i64 i=0; i<n; i++) {
        cin >> p[i];
        if (i > 0) p[i] += p[i-1];
    }

    i64 r = n-m+1;
    vector<i64> rq(r);
    for (i64 i=0; i<n-m+1; i++) {
        rq[i] = p[i+m-1];
        if (i > 0) rq[i] -= p[i-1];
    }

    vector<i64> dp(r, 0);
    for (i64 i=0; i<r; i++) {
        dp[i] = rq[i];
    }
    for (i64 t=1; t<k; t++) {
        vector<i64> dpr(r, 0);
        i64 mxdp = 0;
        for (int i=0; i<r; i++) {
            mxdp = max(mxdp, dp[i]);
            dpr[i] = mxdp;
        }
        for (i64 i=r-1; i>=m; i--) {
            dp[i] = max(dp[i], dpr[i-m] + rq[i]);
        }
    }
    i64 val = 0;
    for (i64 i = 0; i<r; i++) {
        val = max(val, dp[i]);
    }

    cout << val << endl;
    return 0;
}