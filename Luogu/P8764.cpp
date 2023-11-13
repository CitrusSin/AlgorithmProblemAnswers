#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

int digit_count(u64 val) {
    int r = 0;
    while (val) {
        val >>= 1;
        r++;
    }
    return r;
}

constexpr u64 lowbit(u64 x) {
    return x&(~x+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 n, k;
    cin >> n >> k;

    int dgc = digit_count(n);

    u64 dp[dgc][dgc];
    for (int i=0; i<dgc; i++) {
        dp[0][i] = i == 0;
        dp[i][0] = 1;
    }
    //dp[l][k] = dp[l-1][k-1]+dp[l-1][k];
    for (int i=1; i<dgc; i++) {
        for (int j=1; j<dgc; j++) {
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }

    u64 total = 0;
    int total_1 = 0;
    for (int i=0; i<64; i++) {
        total_1 += (n>>i)&1;
    }
    while (n) {
        int p = k-(--total_1);
        if (p >= 0) total += dp[digit_count(lowbit(n))-1][p];
        n -= lowbit(n);
    }
    cout << total << endl;
    return 0;
}