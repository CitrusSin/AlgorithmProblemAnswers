#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    i64 n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (k == 0) {
        cout << s << endl;
        return;
    }

    if (n == 1) {
        cout << ((k%2) ^ (s[0] == '1')) << endl;
        return;
    }

    i64 ct = 0;
    char last_char = '1';
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '0' && last_char == '1') {
            ct++;
        }
        if (ct > k) break;
        last_char = s[i];
        if (s[i] == '0') {
            s[i] = '1';
        }
    }
    if (ct == 0 && k == 1) {
        s.back() = '0';
        cout << s << endl;
        return;
    }
    cout << s << endl;
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