#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> w(n);
    bool flag = false;
    for (int i=0; i<n; i++) {
        cin >> w[i];
        if (w[i] > k) flag = true;
    }
    if (flag) {
        cout << 0 << endl;
        return 0;
    }

    int l=0, r=0;
    int sum = 0;
    int min_len = numeric_limits<int>::max();
    flag = false;
    for (; r<n; r++) {
        if (w[r] > 0) {
            sum += w[r];
            flag = true;
        }
        while (l < r && sum - w[l] >= k) {
            sum -= w[l++];
        }
    }
    return 0;
}