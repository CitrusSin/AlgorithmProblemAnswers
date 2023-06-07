#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_next(const string& pat) {
    int n = pat.size();
    vector<int> next(n+1);
    next[0] = -1;
    int i, j;
    for (i=1, j=0; i<=n; i++, j++) {
        next[i] = pat[i] == pat[j] ? next[j] : j;
        while (j >= 0 && pat[i] != pat[j]) {
            j = next[j];
        }
    }
    next[n] = j;
    return next;
}

vector<int> kmp_match(const string& src, const string& pat, const vector<int>& next) {
    int n = src.size(), m = pat.size();
    vector<int> result;
    for (int i=0, j=0; i<=n; i++, j++) {
        if (j == m) {
            result.push_back(i-1);
            j = next[j];
        }
        if (i == n) break;
        while (j >= 0 && src[i] != pat[j]) {
            j = next[j];
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int w, l;
    cin >> w >> l;
    string msg;
    cin >> msg;
    
    vector<string> words(w);
    for (int i=0; i<w; i++) {
        cin >> words[i];
    }
    
    vector<set<int>> lkp_table(l);
    for (int i=0; i<w; i++) {
        vector<int> matches = kmp_match(msg, words[i], kmp_next(words[i]));
        for (int k : matches) {
            lkp_table[k].insert(words[i].size());
        }
    }
    
    vector<int> dp(l, 0), dp_max(l, 0);
    for (int i=0; i<l; i++) {
        int max_val = 0;
        for (int word_len : lkp_table[i]) {
            int r = i - word_len;
            int smax = (r>=0?dp_max[r]:0) + word_len;
            max_val = max(max_val, smax);
        }
        dp[i] = max_val;
        dp_max[i] = max_val;
        if (i > 0) dp_max[i] = max(dp_max[i], dp_max[i-1]);
    }
    
    int result = l - dp_max[l-1];
    cout << result << endl;
    return 0;
}