#include <bits/stdc++.h>

using namespace std;

int count_str(const string& s) {
    int n = s.size(), cnt = s.size()-1;
    for (int i=2; i<n; i++) {
        if (s[i] == s[i-2]) {
            cnt--;
        }
    }
    return cnt;
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
        cout << count_str(s) << endl;
    }
    return 0;
}