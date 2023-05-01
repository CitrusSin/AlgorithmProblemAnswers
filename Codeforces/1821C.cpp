#include <bits/stdc++.h>

using namespace std;

int solve(const string& s) {
    size_t n = s.size();
    unordered_map<char, vector<int>> char_appearance;
    
    for (size_t i = 0; i < n; i++) {
        char_appearance[s[i]].push_back(i);
    }

    int result = numeric_limits<int>::max();

    for (const auto& p : char_appearance) {
        vector<int> lens;
        int last = -1;
        for (int id : p.second) {
            if (id-last > 1) {
                lens.push_back(id-last-1);
            }
            last = id;
        }
        if (last < n-1) {
            lens.push_back(n-last-1);
        }

        int max_steps = 0;
        for (int l : lens) {
            int st = 0;
            while (l > 0) {
                l >>= 1;
                st++;
            }
            max_steps = max(max_steps, st);
        }

        result = min(result, max_steps);
    }
    return result;
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