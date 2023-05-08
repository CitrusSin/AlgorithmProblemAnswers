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
        
        bool k = true;
        for (size_t i=1; i<n; i++) {
            if (s[i-1] != s[i]) {
                k = false;
                break;
            }
        }
        if (k || n <= 1) {
            cout << -1 << endl;
        } else {
            cout << n-1 << endl;
        }
    }
    return 0;
}