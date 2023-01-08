#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

template <typename Iter>
ull mgsort(Iter b, Iter e) {
    using T = typename iterator_traits<Iter>::value_type;
    
    int len = e-b;
    if (len <= 1) {
        return 0;
    } else if (len == 2) {
        Iter l = b, r = e-1;
        if (*l > *r) {
            T sw = *l;
            *l = *r;
            *r = sw;
            return 1;
        } else return 0;
    }
    
    ull res = 0;
    Iter mid = b+(e-b)/2;
    res += mgsort(b, mid);
    res += mgsort(mid, e);
    
    Iter l = b, r = mid;
    
    vector<T> buf(len);
    int pt = 0;
    while (l < mid && r < e) {
        if (*l <= *r) {
            buf[pt++] = *l++;
        } else {
            buf[pt++] = *r++;
            res += mid-l;
        }
    }
    while (l < mid) {
        buf[pt++] = *l++;
    }
    l--;
    while (r < e) {
        buf[pt++] = *r;
        if (*r < *l) res++;
        r++;
    }
    Iter it = b;
    for (int i=0; i<len; i++) {
        *it++ = buf[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << mgsort(arr.begin(), arr.end()) << endl;
    return 0;
}