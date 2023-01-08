#include <bits/stdc++.h>

using namespace std;

bool check_cutability(vector<int>::const_iterator b, vector<int>::const_iterator e) {
    using it = vector<int>::const_iterator;
    size_t len = e-b-1;
    it first = b, last = e-1;
    if (*first == len || *last == len) {
        return true;
    }
    for (it mid = first+1; mid<=last; mid++) {
        size_t len2 = mid - first - 1;
        if (*first == len2 || *(mid-1) == len2) {
            bool r2 = check_cutability(mid, e);
            if (r2) return true;
        }
    }
    return false;
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

    cout << (check_cutability(arr.begin(), arr.end())?"YES":"NO") << endl;
    return 0;
}