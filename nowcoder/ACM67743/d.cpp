#include <bits/stdc++.h>
#include <limits>

using namespace std;
using i64 = int64_t;

i64 solve1(const vector<i64>& arr) {
    size_t n = arr.size();
    vector<i64> maxpsum(n, 0), maxpsumrev(n, 0);
    for (size_t i=0; i<n; i++) {
        i64 last = 0;
        if (i > 0) last = max<i64>(0, maxpsum[i-1]);
        maxpsum[i] = last + arr[i];
    }
    for (size_t i=n-1; i<n; i--) {
        i64 last = 0;
        if (i < n-1) last = max<i64>(0, maxpsumrev[i+1]);
        maxpsumrev[i] = last + arr[i];
    }

    i64 ltr = numeric_limits<i64>::min(), rtl = numeric_limits<i64>::min();
    for (size_t i=0; i<n; i++) {
        i64 prs = maxpsum[i];
        if (i < n-1) {
            prs = max(prs, maxpsum[i] - arr[i] + arr[i+1]);
        }
        ltr = max(ltr, prs);
    }
    for (size_t i=n-1; i<n; i--) {
        i64 prs = maxpsumrev[i];
        if (i > 0) {
            prs = max(prs, maxpsumrev[i] - arr[i] + arr[i-1]);
        }
        rtl = max(rtl, prs);
    }

    i64 ans = max(ltr, rtl);
    return ans;
}

i64 solve0(const vector<i64>& arr) {
    size_t n = arr.size();
    i64 lp = 0, ans = numeric_limits<i64>::min();
    for (size_t i=0; i<n; i++) {
        i64 last = max<i64>(0, lp);
        lp = last + arr[i];
        ans = max(ans, lp);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<i64> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    if (k == 0) {
        cout << solve0(arr) << endl;
    } else if (k == 1) {
        cout << solve1(arr) << endl;
    }
}