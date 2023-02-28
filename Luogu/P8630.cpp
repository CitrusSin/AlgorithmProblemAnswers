#include <bits/stdc++.h>
using namespace std;

void make_next(const char *str, int *dst) {
    int j=-1;
    for (int i=0; str[i]; i++) {
        if (j >= 0 && str[j] == str[i]) {
            dst[i] = dst[j];
        } else {
            dst[i] = j;
            while (j >= 0 && str[j] != str[i]) j = dst[j];
        }
        j++;
    }
}

int kmp_match(const char *str, const char* pattern, const int *next) {
    int pat_len = strlen(pattern);

    int i=0, j=0;
    for (i=0; str[i] && j < pat_len; i++) {
        if (j>=0 && pattern[j] != str[i]) {
            while (j>=0 && str[i] != pattern[j]) j = next[j];
        }
        j++;
    }
    if (j == pat_len) {
        return i-j;
    }
    return -1;
}

vector<int> make_next_stl(const string& str) {
    size_t len = str.size();
    int *arr = new int[len];
    make_next(str.c_str(), arr);

    vector<int> res(len);
    for (int i=0; i<len; i++) {
        res[i] = arr[i];
    }
    delete[] arr;
    return res;
}

string::const_iterator kmp_match_stl(
        const string& origin,
        string::const_iterator bi,
        const string& pat,
        const vector<int>& next
    ) {
    
    int ofst = bi - origin.cbegin();
    int res = kmp_match(origin.c_str()+ofst, pat.c_str(), next.data());
    if (res >= 0) {
        return bi + res;
    } else {
        return origin.cend();
    }
}

int main() {
    string origin;
    cin >> origin;

    int n;
    cin >> n;

    vector<string> pats(n);
    for (int i=0; i<n; i++) {
        cin >> pats[i];
    }

    vector<vector<int>> nexts;
    nexts.reserve(n);
    for (int i=0; i<n; i++) {
        nexts.push_back(make_next_stl(pats[i]));
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        auto it = kmp_match_stl(origin, origin.cbegin(), pats[i], nexts[i]);
        while (it != origin.cend()) {
            cnt++;
            it = kmp_match_stl(origin, it+1, pats[i], nexts[i]);
        }
    }

    cout << cnt << endl;
    return 0;
}