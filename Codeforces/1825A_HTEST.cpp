#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length(), z=0;
        for (int i=0; i<n; i++) {
            if (s[i] == s[i+1]) {
                z += 1;
            }
            if (z == n-1) {
                cout << "-1" << endl;
            } else {
                cout << n-1 << endl;
            }
        }
    }
}