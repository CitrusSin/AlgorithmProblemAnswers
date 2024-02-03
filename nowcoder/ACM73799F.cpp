#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    string paste;
    string s;
    cin >> s;

    while (m--) {
        string op;
        cin >> op;
        if (op == "cx" || op == "cc") {
            int st, ed;
            cin >> st >> ed;
            st--;
            paste = s.substr(st, ed-st);
            if (op == "cx") s = s.substr(0, st) + s.substr(ed);
        } else if (op == "cv") {
            int idx;
            cin >> idx;

            if (idx >= 0 && idx <= s.size()) s.insert(idx, paste);
        }
    }

    cout << s << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
