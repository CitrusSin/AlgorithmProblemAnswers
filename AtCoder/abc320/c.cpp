#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    array<string, 3> s;
    cin >> s[0] >> s[1] >> s[2];

    set<char> exist_chars;
    array<map<char, set<int>>, 3> mp;
    for (int i=0; i<3; i++) {
        for (int j=0; j<m; j++) {
            mp[i][s[i][j]].insert(j);
            exist_chars.insert(s[i][j]);
        }
    }

    vector<char> sols;

    for (char c : exist_chars) {
        bool success = true;
        for (int r=0; r<3; r++) {
            if (mp[r][c].empty()) {
                success = false;
                break;
            }
        }
        if (success) sols.push_back(c);
    }

    uint32_t ans = numeric_limits<uint32_t>::max();
    for (char c : sols) {
        for (int i : mp[0][c]) {
            for (int j : mp[1][c]) {
                for (int k : mp[2][c]) {
                    array<uint32_t, 3> sp = {i, j, k};
                    sort(sp.begin(), sp.end());
                    if (sp[0] == sp[1] && sp[1] == sp[2]) {
                        sp[1] += m;
                        sp[2] += 2*m;
                    } else if (sp[0] == sp[1]) {
                        sp[1] += m;
                    } else if (sp[1] == sp[2]) {
                        sp[2] += m;
                    }

                    uint32_t rst = *max_element(sp.begin(), sp.end());
                    ans = min(ans, rst);
                }
            }
        }
    }

    if (ans == numeric_limits<uint32_t>::max()) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}