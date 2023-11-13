#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string pat = "codeforces";

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        for (int i=0; i<10; i++) {
            if (s[i] != pat[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}