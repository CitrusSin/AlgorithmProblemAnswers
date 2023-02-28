#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a, int b) {
    return a>b?a:b;
}

int main() {
    char a[201], b[201];
    while (scanf("%s %s", a, b) == 2) {
        long long dp[201][201];
        int a_len = strlen(a), b_len = strlen(b);
        for (int i=0; i<201; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        for (int i=1; i<=a_len; i++) {
            for (int j=1; j<=b_len; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        printf("%ld\n", dp[a_len][b_len]);
    }
    return 0;
}