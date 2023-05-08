#include <bits/stdc++.h>

using namespace std;

map<int, int> prime_decomp(int x) {
    map<int, int> mp;
    for (int i=2; i*i<=x; i++) {
        while (x % i == 0) {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        mp[x]++;
    }
    return mp;
}

size_t solve(const vector<int>& arr) {
    size_t n = arr.size();
    map<int, int> total_decomp;
    for (size_t i=0; i<n; i++) {
        map<int, int> dec = prime_decomp(arr[i]);
        for (const auto& p : dec) {
            total_decomp[p.first] += p.second;
        }
    }
    size_t result = 0;
    size_t pmc = 0;
    for (auto& p : total_decomp) {
        result += p.second/2;
        pmc += p.second % 2;
    }
    result += pmc / 3;
    return result;
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
        for (int i=0; i<n; i++) cin >> arr[i];

        cout << solve(arr) << endl;
    }
    return 0;
}