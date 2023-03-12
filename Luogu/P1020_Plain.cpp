#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr;
    int t;
    while (cin >> t) {
        arr.push_back(t);
    }
    size_t n = arr.size();

    vector<int> dp(n, 1);
    for (size_t i=0; i<n; i++) {
        int longest = 0;
        for (size_t j=0; j<i; j++) {
            if (arr[i] <= arr[j]) {
                longest = max(longest, dp[j]);
            }
        }
        dp[i] = longest+1;
    }
    return 0;
}