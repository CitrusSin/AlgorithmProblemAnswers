#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int cnt = 0;
    for (int i=0; i<n; i+=2) {
        cout << char('A' + cnt) << char('A' + cnt);
        cnt = (cnt + 1) % 26;
    }

    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}