#include <bits/stdc++.h>

using namespace std;

void depth_find(char c, vector<int>& st, int n, vector<map<char, set<int>>>& mp, const function<void(vector<int>)>& cb, int dep = 0) {
    if (dep == n) {
        cb(st);
    } else {
        for (int r : mp[dep][c]) {
            st.push_back(r);
            depth_find(c, st, n, mp, cb, dep+1);
            st.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    set<char> exist_chars;
    vector<map<char, set<int>>> mp(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            mp[i][s[i][j]].insert(j);
            exist_chars.insert(s[i][j]);
        }
    }

    vector<char> sols;

    for (char c : exist_chars) {
        bool success = true;
        for (int r=0; r<n; r++) {
            if (mp[r][c].empty()) {
                success = false;
                break;
            }
        }
        if (success) sols.push_back(c);
    }

    uint32_t ans = numeric_limits<uint32_t>::max();
    for (char c : sols) {
        vector<int> st;
        depth_find(c, st, n, mp, [m, &ans](vector<int> sp) {
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
        });
    }

    if (ans == numeric_limits<uint32_t>::max()) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}