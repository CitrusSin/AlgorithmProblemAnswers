#include <bits/stdc++.h>

using namespace std;

bool detect(const string& str) {
    const char sts[4] = {'M', 'E', 'O', 'W'};
    int s = -1;
    for (char c : str) {
        if (s >= 0 && c == sts[s] || c == sts[s]+32) continue;
        if (s < 3 && (c == sts[s+1] || c == sts[s+1]+32)) {
            s++;
        } else {
            return false;
        }
    }
    return s == 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << (detect(s)?"YES":"NO") << endl;
    }
    return 0;
}