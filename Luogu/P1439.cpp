#include <bits/stdc++.h>

using namespace std;

size_t lis(const vector<int>& arr) {
    size_t n = arr.size();
    if (n == 0) return 0;

    vector<int> lst;
    lst.reserve(n);
    lst.push_back(arr[0]);
    for (size_t i=1; i<n; i++) {
        size_t max_len = lower_bound(lst.begin(), lst.end(), arr[i]) - lst.begin();
        if (max_len == lst.size()) {
            lst.push_back(arr[i]);
        } else {
            lst[max_len] = min(lst[max_len], arr[i]);
        }
    }
    return lst.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> indices;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        indices[p] = i;
    }

    vector<int> c(n);
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        c[i] = indices[p];
    }

    cout << lis(c) << endl;
    return 0;
}