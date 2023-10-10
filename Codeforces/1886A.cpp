#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n <= 6 || n == 9) {
        cout << "NO" << '\n';
        return;
    }

    int a = 1, b = 2, c = n-3;
    if (c % 3 == 0) {
        b+=2;
        c-=2;
    }
    cout << "YES" << '\n';
    cout << a << ' ' << b << ' ' << c << '\n';
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