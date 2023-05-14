#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        size_t n = s.size();
        set<char> chs;
        for (size_t i=0; i<n/2; i++) {
            chs.insert(s[i]);
        }
        cout << (chs.size() <= 1 ? "NO" : "YES") << endl;
    }
    return 0;
}