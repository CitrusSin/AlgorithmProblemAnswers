#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int a[N];
int n, m;
int dp[N][N];
int cnt = 0;

int dfs(int bn, int bm) {
    if (bn == n) return bm==m; 
    if (bm == m) return 1;
    if (bn > n) return 0;
    if (dp[bn][bm]) return dp[bn][bm];

    int res = 0;
    for (int c=0; c<=a[bn] && bm+c<=m; c++) {
        res += dfs(bn+1, bm+c);
        res %= 1000007;
    }
    dp[bn][bm] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << dfs(0, 0) << endl;
    return 0;
}