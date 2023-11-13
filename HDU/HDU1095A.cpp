#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

string judge(i64 k, i64 n) {
    i64 beg = k+1;
    i64 d = 4*k+2;

    if (n == 0) {
        return "Bob";
    }
    if ((n-beg)%d == 0) {
        return "Bob";
    }
    return "Alice";
}

void solve() {
    i64 k, n;
    cin >> k >> n;

    cout << judge(k, n) << endl;
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