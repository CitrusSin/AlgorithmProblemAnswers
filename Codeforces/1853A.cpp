#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int64_t> b(n-1);
    for (int i=0; i<n-1; i++) {
        b[i] = a[i+1]-a[i];
    }
    for (int i=0; i<n-1; i++) {
        if (b[i] < 0) {
            cout << "0" << endl;
            return;
        }
    }

    int64_t rst = *min_element(b.begin(), b.end());
    cout << (rst/2)+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}