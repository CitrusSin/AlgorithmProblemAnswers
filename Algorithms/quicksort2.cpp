#include <bits/stdc++.h>

using namespace std;

template <typename RAIter, typename Comparator>
void quick_sort(RAIter b, RAIter e, Comparator comp) {
    if (b >= e) return;
    RAIter l = b, r = e-1;
    if (r-l==0) return;
    if (r-l==1) {
        if (!comp(*l, *r)) {
            auto sw = *l;
            *l = *r;
            *r = sw;
        }
        return;
    }

    bool mode = false;
    while (l != r) {
        if (!comp(*l, *r)) {
            auto sw = *l;
            *l = *r;
            *r = sw;
            mode = !mode;
        }
        if (mode) {
            l++;
        } else {
            r--;
        }
    }

    quick_sort(b, l, comp);
    quick_sort(l+1, e, comp);
}

template <typename RAIter>
void quick_sort(RAIter b, RAIter e) {
    using element = typename iterator_traits<RAIter>::value_type;
    quick_sort(b, e, less<element>());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand(time(NULL));
    vector<int> arr(100000);

    chrono::time_point tp0 = chrono::system_clock::now();
    for (int k=0; k<1000; k++) {
        for (int i=0; i<100000; i++) {
            arr[i] = rand();
        }
        quick_sort(arr.begin(), arr.end());
        
        bool check_sign = true;
        for (int i=0; i<99999; i++) {
            if (arr[i]>arr[i+1]) {
                check_sign = false;
                break;
            }
        }

        cout << "Quick Sort Check #" << k+1 << ": " << (check_sign?"Check well":"Check not ok") << endl;
    }
    chrono::time_point tp1 = chrono::system_clock::now();
    cout << "QuickSort time used " << chrono::duration_cast<chrono::milliseconds>(tp1-tp0).count() << "ms" << endl;

    tp0 = chrono::system_clock::now();
    for (int k=0; k<1000; k++) {
        for (int i=0; i<100000; i++) {
            arr[i] = rand();
        }
        sort(arr.begin(), arr.end());
        
        bool check_sign = true;
        for (int i=0; i<99999; i++) {
            if (arr[i]>arr[i+1]) {
                check_sign = false;
                break;
            }
        }

        cout << "StdSort Check #" << k+1 << ": " << (check_sign?"Check well":"Check not ok") << endl;
    }
    tp1 = chrono::system_clock::now();
    cout << "StdSort time used " << chrono::duration_cast<chrono::milliseconds>(tp1-tp0).count() << "ms" << endl;

    return 0;
}
