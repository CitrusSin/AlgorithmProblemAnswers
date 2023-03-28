#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 R = 1000000000000;

u64 count_str(const string& s) {
    int c1 = 0;
    u64 op_cnt = 0;

    size_t n = s.size();
    u64 dp = 0;
    for (size_t i=0; i<n; i++) {
        char c = s[i];
        if (c == '0') {
            if (c1 != 0) {
                dp += R+1;
                if (i > 0 && s[i-1] == '1') {
                    dp = min(dp, (c1-1)*(R+1)+R);
                }
            }
        } else if (c == '1') {
            if (c1*(R+1) < dp) {
                dp = c1*(R+1);
            }
            c1++;
        }
    }
    return min(dp, c1*(R+1));
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
        cout << count_str(s) << endl;
    }
    return 0;
}