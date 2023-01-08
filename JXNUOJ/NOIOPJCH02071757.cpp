#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull selection_count(int arr[], int n) {
    ull dp[n+1][41];
    dp[0][0] = 1;
    for (int vol=1; vol<=40; vol++) {
        dp[0][vol] = 0;
    }

    for (int i=1; i<=n; i++) {
        for (int vol=0; vol<=40; vol++) {
            int remain_vol = vol - arr[i-1];
            if (remain_vol >= 0) {
                dp[i][vol] = dp[i-1][remain_vol] + dp[i-1][vol];
            } else {
                dp[i][vol] = dp[i-1][vol];
            }
        }
    }

    return dp[n][40];
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << selection_count(arr, n) << endl;
    return 0;
}