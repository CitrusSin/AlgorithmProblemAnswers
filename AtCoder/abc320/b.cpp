#include <bits/stdc++.h>

using namespace std;

bool palin(const string& s) {
    size_t n = s.size();
    for (size_t i=0, j=n-1; i<j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    size_t min_len = 1;
    for (size_t r = 0; r < s.size(); r++) {
        for (size_t l = min_len+1; l <= s.size() - r; l++) {
            if (palin(s.substr(r, l))) min_len = max(min_len, l);
        }
    }

    cout << min_len << endl;
    return 0;
}