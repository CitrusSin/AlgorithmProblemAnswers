#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

template <typename Iter>
u64 mgsort(Iter b, Iter e) {
    using element_type = typename iterator_traits<Iter>::value_type;

    size_t len = e-b;
    if (len == 0 || len == 1) return 0;
    if (len == 2) {
        Iter l = b, r = e-1;
        if (*l > *r) {
            auto sw = *l;
            *l = *r;
            *r = sw;
            return 1;
        } else return 0;
    }

    u64 cnt = 0;
    Iter mid = b+len/2;
    if (b != mid) cnt += mgsort(b, mid);
    if (mid != e) cnt += mgsort(mid, e);

    vector<element_type> buf_arr;
    buf_arr.reserve(len);
    Iter l = b, r = mid;
    while (l < mid && r < e) {
        if (*l <= *r) {
            buf_arr.push_back(*l++);
        } else {
            cnt += (mid - l);
            buf_arr.push_back(*r++);
        }
    }
    while (l < mid) {
        buf_arr.push_back(*l++);
    }
    while (r < e) {
        buf_arr.push_back(*r++);
    }

    Iter p = b;
    for (const element_type& elem : buf_arr) {
        *p++ = elem;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_map<string, int> teacher_map;
    for (int i=0; i<n; i++) {
        string name;
        cin >> name;
        teacher_map[name] = i;
    }

    vector<int> unsorted_arr(n);
    for (int i=0; i<n; i++) {
        string name;
        cin >> name;
        unsorted_arr[i] = teacher_map[name];
    }

    u64 cnt = mgsort(unsorted_arr.begin(), unsorted_arr.end());
    cout << cnt << endl;
    return 0;
}