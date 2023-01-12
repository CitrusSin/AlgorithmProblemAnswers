#include <bits/stdc++.h>
using namespace std;

bool dfs_internal(const int *a, bool *res, const int *suffix_sum, int n, int x, int i0, const function<bool(bool*, int)> &callback) {
    if (x == 0) {
        for (int i=i0; i<n; i++) res[i] = false;
        return callback(res, n);
    } else if (x <= a[i0]) {
        if (x == a[i0]) {
            res[i0] = true;
            for (int i=i0+1; i<n; i++) res[i] = false;
            return callback(res, n);
        }
        res[i0] = false;
        if (i0+1 < n && suffix_sum[i0+1] >= x) {
            bool r = dfs_internal(a, res, suffix_sum, n, x, i0+1, callback);
            if (!r) return false;
        }
    } else if (x > 0) {
        res[i0] = true;
        if (i0+1 < n && suffix_sum[i0] >= x) {
            bool r = dfs_internal(a, res, suffix_sum, n, x-a[i0], i0+1, callback);
            if (!r) return false;
        }
        res[i0] = false;
        if (i0+1 < n && suffix_sum[i0+1] >= x) {
            bool r = dfs_internal(a, res, suffix_sum, n, x, i0+1, callback);
            if (!r) return false;
        }
    }
    return true;
}

void dfs(const int *a, int n, int x, const function<bool(bool*, int)> &callback) {
    bool res[n];
    int suffix_sum[n];
    for (int i=0; i<n; i++) {
        res[i] = false;
    }

    suffix_sum[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--) {
        suffix_sum[i] = suffix_sum[i+1] + a[i];
    }
    dfs_internal(a, res, suffix_sum, n, x, 0, callback);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<int>());

    bool must[n];
    for (int i=0; i<n; i++) must[i] = true;
    dfs(arr, n, x, [&must](bool *bs, int n) {
        bool flag = false;
        for (int i=0; i<n; i++) {
            flag |= must[i] &= bs[i];
        }
        return flag;
    });

    vector<int> must_coins;
    for (int i=n-1; i>=0; i--) {
        if (must[i]) {
            must_coins.push_back(arr[i]);
        }
    }

    cout << must_coins.size() << endl;
    bool flag = false;
    for (int c : must_coins) {
        if (flag) cout << " ";
        flag = true;
        cout << c;
    }
    cout << endl;
    return 0;
}