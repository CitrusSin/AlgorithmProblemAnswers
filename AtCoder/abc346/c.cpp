#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;

    vector<int64_t> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int64_t sum = k * (k+1) / 2;
    for (int64_t v : a) if (v <= k) sum -= v;

    cout << sum << endl;
}