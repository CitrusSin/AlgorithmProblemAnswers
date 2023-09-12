#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 check_line(const vector<u64>& pfsum, u64 w) {
    size_t n = pfsum.size(), li = 0;
    u64 rw = 0, lines = 0;
    for (size_t i=0; i<n; i++) {
        if (pfsum[i] - (li ? pfsum[li-1] : 0) + (i - li) > w) {
            lines++;
            li = i;
        }
    }
    lines++;
    return lines;
}

u64 find_width(const vector<u64>& ls, u64 m) {
    size_t n = ls.size();
    vector<u64> pfsum = ls;
    for (size_t i=1; i<n; i++) {
        pfsum[i] += pfsum[i-1];
    }

    u64 l = *max_element(ls.begin(), ls.end()), r = pfsum[n-1] + n - 1;
    while (l < r) {
        u64 mid = l + (r-l)/2;
        if (check_line(pfsum, mid) > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<u64> l(n);
    for (int i=0; i<n; i++) cin >> l[i];

    cout << find_width(l, m) << endl;
    return 0;
}