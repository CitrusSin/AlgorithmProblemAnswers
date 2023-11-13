#include <bits/stdc++.h>

using namespace std;

int log2int(int x) {
    int mask = 0;
    int bits = -1;
    while (x&~mask) {
        mask <<= 1;
        mask |= 1;
        bits++;
    }
    return bits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> cost, val;
    for (int i=0; i<n; i++) {
        int v, w, m;
        cin >> v >> w >> m;
        int l = log2int(m);
        int rem = m-((1<<l)-1);
        cost.push_back(rem*w);
        val.push_back(rem*v);
        for (int b=0; b<l; b++) {
            int k = 1 << b;
            cost.push_back(k*w);
            val.push_back(k*v);
        }
    }

    vector<int> dp(c+1, 0);
    int bn = cost.size();
    for (int i=0; i<bn; i++) {
        for (int j=c; j>=cost[i]; j--) {
            dp[j] = max(dp[j], dp[j-cost[i]]+val[i]);
        }
    }
    cout << dp[c] << endl;
    return 0;
}