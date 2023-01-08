#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

template <typename Iter>
u64 mgsort(Iter b, Iter e) {
    using elem = typename iterator_traits<Iter>::value_type;

    size_t len = e-b;
    if (len == 0 || len == 1) return 0;
    if (len == 2) {
        Iter x = b, y = e-1;
        if (*x > *y) {
            elem sw = *x;
            *x = *y;
            *y = sw;
            return 1;
        } else return 0;
    }
    Iter mid = b + len/2;
    u64 res = 0;
    res += mgsort(b, mid);
    res += mgsort(mid, e);

    Iter l = b, r = mid;

    vector<elem> sort_buf;
    sort_buf.reserve(len);

    while (l != mid && r != e) {
        if (*l > *r) {
            sort_buf.push_back(*r++);
            res += mid-l;
        } else {
            sort_buf.push_back(*l++);
        }
    }
    while (l != mid) {
        sort_buf.push_back(*l++);
    }
    while (r != e) {
        sort_buf.push_back(*r++);
    }

    Iter wr = b;
    for (int i=0; i<len; i++) {
        *wr++ = sort_buf[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        u64 res = mgsort(arr.begin(), arr.end());
        cout << res << endl;
    }
    return 0;
}