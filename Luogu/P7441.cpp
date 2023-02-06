#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        u64 a, b, k;
        cin >> a >> b >> k;
        if (a > 0 && b > 0) {
            cout << min(k/a, k/b) << endl;
        } else if (a == 0 && b == 0) {
            cout << 0 << endl;
        } else {
            cout << (k%max(a, b)?0:1) << endl;
        }
    }
    return 0;
}