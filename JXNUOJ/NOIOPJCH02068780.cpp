#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int heights[n];
    for (int i=0; i<n; i++) {
        cin >> heights[i];
    }

    int dp[n];
    for (int i=0; i<n; i++) {
        if (i == 0) {
            dp[0] = 1;
        } else {
            int result = 1;
            for (int j=0; j<i; j++) {
                if (heights[j]>=heights[i]) {
                    result = max(result, dp[j] + 1);
                }
            }
            dp[i] = result;
        }
    }

    int max_len = 1;
    for (int i=0; i<n; i++) {
        if (dp[i] > max_len) {
            max_len = dp[i];
        }
    }

    cout << max_len << endl;
    return 0;
}