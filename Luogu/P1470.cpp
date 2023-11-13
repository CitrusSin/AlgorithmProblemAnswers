#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_next(const string& pat) {
    int n = pat.size();
    vector<int> next(n+1, -1);
    for (int i=1,j=0; i<=n; i++,j++) {
        if (i < n && pat[i] == pat[j]) {
            next[i] = next[j];
        } else {
            next[i] = j;
            while (j >= 0 && i < n && pat[i] != pat[j]) {
                j = next[j];
            }
        }
    }
    return next;
}

vector<int> kmp_match_all(
    const string& src,
    const string& pat,
    const vector<int>* next_ptr = nullptr
) {
    vector<int> next_backup;
    if (next_ptr == nullptr) {
        next_backup = kmp_next(pat);
        next_ptr = &next_backup;
    }

    const vector<int> &next = *next_ptr;
    int n = src.size(), np = pat.size();
    vector<int> results;
    for (int i=0,j=0; i<=n; i++,j++) {
        if (j == np) {
            results.push_back(i-j);
            j = next[j];
        }
        if (i < n) {
            while (j >= 0 && src[i] != pat[j]) {
                j = next[j];
            }
        }
    }
    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> p;

    string value;
    cin >> value;
    while (value != ".") {
        p.push_back(value);
        cin >> value;
    }

    while (cin.peek() != '\n') cin.get();
    cin.get();

    string src;
    while (cin) {
        string line;
        cin >> line;
        src += line;
    }

    int np = p.size();
    vector< vector<int> > p_match(src.size());
    for (int idx=0; idx<np; idx++) {
        for (int pos : kmp_match_all(src, p[idx])) {
            p_match[pos+p[idx].size()-1].push_back(idx);
        }
    }

    int n = src.size();

    bool *dp = new bool[n];
    memset(dp, 0, n*sizeof(bool));
    for (int i=0; i<n; i++) {
        for (int match_idx : p_match[i]) {
            int prev_idx = i-p[match_idx].size();
            dp[i] |= prev_idx>=0?dp[prev_idx]:true;
            if (dp[i]) break;
        }
    }
    int max_idx = n-1;
    while (max_idx >= 0 && !dp[max_idx]) max_idx--;
    delete[] dp;

    cout << max_idx + 1 << endl;
    return 0;
}