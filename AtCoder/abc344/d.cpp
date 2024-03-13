#include <bits/stdc++.h>
#include <limits>
#include <string_view>

using namespace std;

int main() {
    string t;
    cin >> t;

    string_view tsv(t);

    int n;
    cin >> n;
    vector<vector<string>> strs(n);
    vector<vector<pair<int, int>>> matches(t.size());
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        strs[i].reserve(a);
        for (int j=0; j<a; j++) {
            string s;
            cin >> s;
            strs[i].push_back(s);

            if (t.size() < s.size()) continue;
            size_t n = s.size();
            size_t r = t.size() - n + 1;
            for (size_t u=0; u < r; u++) {
                if (tsv.substr(u, n) == s) {
                    matches[u].emplace_back(i, j);
                }
            }
        }
    }

    vector<int> dp(t.size(), numeric_limits<int>::max());
    vector<set<pair<int, int>>> record(t.size());
    for (size_t i=t.size()-1; i < t.size(); i--) {
        for (auto& [p, q] : matches[i]) {
            if (strs[p][q].size() + i > t.size()) continue;
            if (strs[p][q].size() + i == t.size()) {
                dp[i] = 1;
                record[i].clear();
                record[i].emplace(p, q);
                continue;
            }
            if (dp[i+strs[p][q].size()] != numeric_limits<int>::max()) {
                if (!record[i+strs[p][q].size()].count(make_pair(p, q))) {
                    dp[i] = min(dp[i], dp[i+strs[p][q].size()]+1);
                    record[i] = record[i+strs[p][q].size()];
                    record[i].emplace(p, q);
                }
            }
        }
    }

    int fin = dp[0];
    if (fin == numeric_limits<int>::max()) fin = -1;
    cout << fin << '\n';
    return 0;
}