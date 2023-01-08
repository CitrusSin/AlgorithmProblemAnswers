#include <bits/stdc++.h>
using namespace std;


vector<int64_t> kmp_next(const string& str) {
    size_t n = str.size();
    vector<int64_t> next(n, -1);
    int64_t i=1, j=0;
    while (i < n) {
        if (str[i] == str[j]) {
            next[i] = next[j];
        } else {
            next[i] = j;
            while (j >= 0 && str[i] != str[j]) {
                j = next[j];
            }
        }
        i++;
        j++;
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
    string str = "cabcabca";
    vector<int64_t> next = kmp_next(str);
    return 0;
}