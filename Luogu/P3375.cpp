#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using u64 = unsigned long long int;

template <typename ChIter>
vector<i64> kmp_next(const string& str, ChIter j_rec) {
    u64 n = str.size();
    vector<i64> next(n, -1);
    for (i64 i=1,j=0; i < n; i++,j++) {
        if (str[i] == str[j]) {
            next[i] = next[j];
            *j_rec++ = j;
        } else {
            next[i] = j;
            *j_rec++ = j;
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
u64 kmp_match(const string& str, const string& pat, const vector<i64>& next, int start_pos = 0) {
    i64 i=start_pos-1, j=-1;
    i64 n = str.size(), np = pat.size();
    i64 maxj = 0;
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
    if (j == np) return i-np;
    return (1ull << 63) | maxj;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    s2.push_back('\0');
    vector<i64> rec(s2.length()-1);
    vector<i64> next = kmp_next(s2, rec.begin());
    s2.pop_back();
    next.pop_back();

    u64 mi = kmp_match(s1, s2, next);
    while ((mi & (1ull<<63)) == 0) {
        cout << mi+1 << endl;
        mi = kmp_match(s1, s2, next, mi+1);
    }

    for (int i : rec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
