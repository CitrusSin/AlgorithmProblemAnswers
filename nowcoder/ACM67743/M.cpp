#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<uint64_t> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    vector<int> psums(n, 0);
    array<vector<int>, 9> remcc4;
    array<int, 10> singles;
    singles.fill(0);
    for (int i=0; i<n; i++) {
        for (char c : to_string(arr[i])) {
            psums[i] += c - '0';
        }
        if (arr[i] > 10 && arr[i] % 4 == 0) {
            remcc4[psums[i] % 9].push_back(i);
        } else if (arr[i] < 10) {
            singles[arr[i]]++;
        }
    }

    uint64_t ans = 0;
    for (int i=0; i<n; i++) {
        int rem = psums[i] % 9;
        vector<int>& opposites = remcc4[(9-rem) % 9];
        uint64_t opcount = opposites.size();
        if (rem == 0 && arr[i] % 4 == 0 /*&& arr[i] > 10*/) opcount--;
        ans += opcount;

        int digit = (9-rem)%9;
        uint64_t si = singles[digit];
        int sp = arr[i] % 10;
        if ((sp * 10 + digit) % 4 == 0) {
            ans += si;
        }

        if (rem == 0) {
            si = singles[9];
            digit = 9;
            if (arr[i] < 10) {
                si--;
            }
            if ((sp * 10 + digit) % 4 == 0) {
                ans += si;
            }
        }
    }

    cout << ans << endl;

    return 0;
}