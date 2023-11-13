#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, w;
        cin >> n >> w;

        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());

        int cnt = 0, idx = 0;
        while (w > 0) {
            w -= a[idx++];
            cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}