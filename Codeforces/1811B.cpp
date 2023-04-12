#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int64_t n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        int64_t l1 = min(min(x1, n-x1+1), min(y1, n-y1+1));
        int64_t l2 = min(min(x2, n-x2+1), min(y2, n-y2+1));
        cout << abs(l1-l2) << endl;
    }
    return 0;
}