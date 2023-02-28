#include <bits/stdc++.h>

using namespace std;

inline int lowbit(int x) {
    return x & -x;
}

unsigned long long solve(int *arr, int n, int m) {
    unsigned long long dp[n][m];
    unsigned long long bit[n][m];
    dp[0][0] = 1;
    for (int len=1; len<=m; len++) {
        for (int i=0; i<n; i++) {
            dp[i][len-1] = 0;
            bit[i][len-1] = 0;
        }
        for (int i=len-1; i<n; i++) {
            if (len == 1) {
                dp[i][0] = 1;
                for (int i2=i+1; i2<=n; i2+=lowbit(i2)) {
                    if (arr[i2-1] > arr[i]) {
                        bit[i2-1][0] += 1;
                        bit[i2-1][0] %= 1000000007;
                    }
                }
            } else {
                unsigned long long result = 0;
                /*
                for (int k=len-2; k<i; k++) {
                    if (arr[k] < arr[i]) {
                        result += dp[k][len-2];
                        result %= 1000000007;
                    }
                }
                */
                for (int k=i+1; k>0; k-=lowbit(k)) {
                    result += bit[k-1][len-2];
                    result %= 1000000007;
                }
                dp[i][len-1] = result;

                for (int i2=i+1; i2<=n; i2+=lowbit(i2)) {
                    if (arr[i2-1] > arr[i]) {
                        bit[i2-1][len-1] += result;
                        bit[i2-1][len-1] %= 1000000007;
                    }
                }
            }
        }
    }
    unsigned long long total = 0;
    for (int i=m-1; i<n; i++) {
        total += dp[i][m-1];
        total %= 1000000007;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int k=0; k<t; k++) {
        int n, m;
        cin >> n >> m;

        int arr[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << "Case #" << k+1 << ": " << solve(arr, n, m) << endl;
    }
    return 0;
}