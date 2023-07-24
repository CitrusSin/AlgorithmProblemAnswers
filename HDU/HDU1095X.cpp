#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i=1; i<s.size(); i++) {
        if (s[i] == s[i-1]) cnt++;
    }

    cout << cnt << endl;
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