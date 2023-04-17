#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "^") {
        cout << 1 << endl;
        return;
    }

    int n = s.size();

    char sv = '\0';
    int last_count = 0, total_count = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '^') {
            last_count++;
            sv = '^';
        } else if (s[i] == '_') {
            if (i == 0 || sv != '^') {
                total_count++;
            }
            last_count = 0;
            sv = '_';
        }
    }
    if (sv == '_') {
        total_count++;
    }
    cout << total_count << endl;
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