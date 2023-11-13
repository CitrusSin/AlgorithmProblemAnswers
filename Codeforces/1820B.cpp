#include <bits/stdc++.h>

using namespace std;

int64_t solve(const string& s) {
    int longest = 0, length = 0;
    bool flag = true;
    for (int i=0; i<2; i++) {
        for (char c : s) {
            if (c == '1') {
                length++;
                if (length > longest) {
                    longest = length;
                }
            } else {
                length = 0;
                flag = false;
            }
        }
    }
    if (flag) {
        int64_t res = s.length();
        return res*res;
    }
    int64_t n = (longest+1)/2;
    int64_t m = longest+1-n;
    return n * m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}