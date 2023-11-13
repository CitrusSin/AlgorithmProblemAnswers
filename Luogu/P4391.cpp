#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> kmp_next(const string& str) {
    size_t n = str.size();
    vector<i64> next(n, -1);
    for (i64 i=1,j=0; i<n; i++,j++) {
        if (str[i] == str[j]) {
            next[i] = next[j];
        } else {
            next[i] = j;
            while (j >= 0 && str[i] != str[j]) {
                j = next[j];
            }
        }
    }
    return next;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;
    str.push_back('\0');
    vector<i64> next = kmp_next(str);

    i64 res = n - next[n];
    cout << res << endl;
    return 0;
}