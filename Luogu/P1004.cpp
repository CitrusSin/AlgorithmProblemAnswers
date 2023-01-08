#include <iostream>

using namespace std;

template <typename Num>
inline const Num &max4(const Num &a, const Num &b, const Num &c, const Num &d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int n;
    cin >> n;
    
    int square[9][9] = {0};
    int a, b, c;
    while (true) {
        scanf("%d%d%d", &a, &b, &c);
        if (!(a==0&&b==0&&c==0)) {
            square[a-1][b-1] = c;
        } else {
            break;
        }
    }

    int dp[17][9][9] = {0};
    for (int sum=0; sum<2*n-1; sum++) {
        for (int x1=0; x1<=sum; x1++) {
            for (int x2=0; x2<=sum; x2++) {
                int y1 = sum-x1;
                int y2 = sum-x2;
                int val = 0;
                if (x1 > 0 && x2 > 0) {
                    val = max4(dp[sum-1][x1-1][x2-1], dp[sum-1][x1][x2-1], dp[sum-1][x1-1][x2], dp[sum-1][x1][x2]) + square[x1][y1] + square[x2][y2];
                } else if (x1>0 && x2==0) {
                    val = max(dp[sum-1][x1-1][x2], dp[sum-1][x1][x2]) + square[x1][y1] + square[x2][y2];
                } else if (x1==0 && x2>0) {
                    val = max(dp[sum-1][x1][x2-1], dp[sum-1][x1][x2]) + square[x1][y1] + square[x2][y2];
                } else {
                    val = square[x1][y1] + square[x2][y2];
                }
                if (x1 == x2) {
                    val -= square[x1][y1];
                }
                dp[sum][x1][x2] = val;
            }
        }
    }

    cout << dp[2*n-2][n-1][n-1] << endl;
    return 0;
}