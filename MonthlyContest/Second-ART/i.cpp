#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename RAIter> i64 merge_sort_count(RAIter begin, RAIter end) {
    using element = typename iterator_traits<RAIter>::value_type;
    if (end-begin<=1) {
        return 0;
    }
    if (end-begin==2) {
        element &a = *begin, &b = *(begin+1);
        if (a<b) {
            element sw = a;
            a = b;
            b = sw;
            return 1;
        }
        return 0;
    }
    
    RAIter mid = begin+(end-begin)/2;
    i64 counter = 0;
    counter += merge_sort_count(begin, mid);
    counter += merge_sort_count(mid, end);
    
    size_t len = end-begin;
    vector<element> temp_arr;
    RAIter a = begin, b = mid;
    for (int i=0; i<len; i++) {
        if (*a < *b && b < end) {
            temp_arr.push_back(*b++);
            counter += (mid-a);
        } else if (a >= mid) {
            temp_arr.push_back(*b++);
        } else {
            temp_arr.push_back(*a++);
        }
    }
    RAIter it = begin;
    for (int i=0; i<len; i++) {
        *it++ = temp_arr[i];
    }
    return counter;
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
        i64 count = merge_sort_count(arr.begin(), arr.end());
        cout << count << endl;
    }
    return 0;
}