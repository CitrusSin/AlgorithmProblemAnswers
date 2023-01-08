#include <bits/stdc++.h>

using namespace std;

long long max_mul(const char* str, int k) {
    int len = strlen(str);
    char str_buf[len+1];
    strcpy(str_buf, str);

    long long dp[len][len+1][k+1];
    for (int i=0; i<len; i++) {
        for (int j=0; j<len+1; j++) {
            for (int m=0; m<k+1; m++) {
                dp[i][j][m] = 0ll;
            }
        }
    }

    // Initialization
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len+1; j++) {
            char reserve = str_buf[j];
            str_buf[j] = '\0';
            sscanf(str_buf+i, "%d", &dp[i][j][0]);
            str_buf[j] = reserve;
        }
    }

    for (int k2=1; k2<=k; k2++) {
        for (int begin=0; begin<len; begin++) {
            for (int end=begin+1; end<len+1; end++) {
                long long max_val = 0;
                for (int i=begin+1; i<=end-begin-1; i++) {
                    int j_max = min(i-begin-1, k2-1);
                    for (int j=0; j<=j_max; j++) {
                        long long val = dp[begin][i][j]*dp[i][end][k2-j-1];
                        if (val > max_val) {
                            max_val = val;
                        }
                    }
                }
                dp[begin][end][k2] = max_val;
            }
        }
    }

    return dp[0][len][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    char str[n+1];
    cin >> str;

    long long result = max_mul(str, k);
    cout << result << endl;
    return 0;
}