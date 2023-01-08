#include <bits/stdc++.h>
//#include <cinttypes>
using namespace std;

vector<int64_t> kmp_next(const string& str) {
    size_t n = str.size();
    vector<int64_t> next(n, -1);
    int64_t i=0, j=-1;
    while (i < n) {
        if (j == -1 || str[i] == str[j]) {
            if (j != -1) {
                next[i] = next[j];
            }
            i++;
            j++;
        } else {
            next[i] = j;
            while (j >= 0 && str[i] != str[j]) {
                j = next[j];
            }
        }
    }
    return next;
}

/*
 *  Return value:
 *  Highest bit
 *      1 => (1<<63)|max_prefix_length
 *      0 => first matched index
 */
size_t kmp_match(const string& str, const string& pat, const vector<int64_t>& next, int start_pos = 0) {
    int64_t i=start_pos-1, j=-1;
    int64_t n = str.size(), np = pat.size();
    int64_t maxj = 0;
    while (i < n) {
        if (j == np) {
            return i-np;
        } else if (j == -1 || str[i] == pat[j]) {
            i++;
            j++;
            if (j > maxj) maxj = j;
        } else {
            while (j >= 0 && str[i] != pat[j]) {
                j = next[j];
            }
        }
    }
    return (1ull << 63) | maxj;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() < s2.size()) {
        swap(s1, s2);
    }
    
    size_t max_len = 0;
    size_t patl = s2.size();
    for (size_t i=0; i<patl; i++) {
        string subpat = s2.substr(i);
        vector<int64_t> next = kmp_next(subpat);
        size_t res = kmp_match(s1, subpat, next);
        size_t len = res&(1ull<<63)?res&~(1ull<<63):subpat.size();
        if (len > max_len) max_len = len;
    }

    cout << max_len << endl;
    return 0;
}