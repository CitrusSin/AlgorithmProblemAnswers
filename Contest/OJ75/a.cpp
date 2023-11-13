#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

size_t find_split(const vector<u64>& arr, u64 x) {
    size_t l = 0, r = arr.size()-1;
    while (l < r) {
        size_t mid = l + (r-l)/2;
        if (arr[mid] >= x) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 n, q;
    cin >> n >> q;
    vector<u64> arr(n);
    for (size_t i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    size_t sz = arr.size();
    vector<u64> sums(sz);
    sums[0] = arr[0];
    for (size_t i=1; i<sz; i++) {
        sums[i] = sums[i-1] + arr[i];
    }

    while (q--) {
        u64 p;
        cin >> p;
        u64 sp = find_split(arr, p);
        u64 cnt = 0;
        if (sp > 0) {
            cnt += (p*sp)-sums[sp-1];
        }
        if (sp < n) {
            cnt += (sums.back()-(sp>0?sums[sp-1]:0))-p*(n-sp);
        }
        cout << cnt << endl;
    }
    return 0;
}