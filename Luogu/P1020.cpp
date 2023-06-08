#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int p;
    vector<int> a;
    while (cin >> p) {
        a.push_back(p);
    }

    int n = a.size();

    int max_len = 0;

    vector<int> lmv(n, 0);
    for (int i=0; i<n; i++) {
        int s = upper_bound(lmv.begin(), lmv.end(), a[i], greater<int>()) - lmv.begin();
        while (s >= n) s--;
        lmv[s] = max(lmv[s], a[i]);

        max_len = max(max_len, s+1);
    }

    cout << max_len << endl;

    int max_len2 = 0;

    vector<int> lmv2(n, numeric_limits<int>::max());
    for (int i=0; i<n; i++) {
        int s = lower_bound(lmv2.begin(), lmv2.end(), a[i]) - lmv2.begin();
        while (s >= n) s--;
        lmv2[s] = min(lmv2[s], a[i]);

        max_len2 = max(max_len2, s+1);
    }

    cout << max_len2 << endl;
    return 0;
}