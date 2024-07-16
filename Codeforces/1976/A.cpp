#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool check = true;

    // check 1
    for (char c : s) {
        if (!(c >= 'a' && c <= 'z' || c >= '0' && c <= '9')) {
            check = false;
            break;
        }
    }

    for (size_t i=1; i<s.size(); i++) {
        if (s[i-1] >= 'a' && s[i-1] <= 'z' && s[i] >= '0' && s[i] <= '9') {
            check = false;
            break;
        }
    }

    string s2 = s;
    sort(s2.begin(), s2.end());

    cout << (check && s2 == s ? "YES" : "NO") << '\n';
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