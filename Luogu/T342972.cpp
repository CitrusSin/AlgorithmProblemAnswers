#include <bits/stdc++.h>

using namespace std;

int solve(const string& s) {
    if (s == "") return 0;

    array<int, 26> arr;
    for (int i=0; i<26; i++) arr[i] = 0;
    for (char c : s) arr[c-'a']++;
    char mxc = 'a';
    for (char c = 'a'; c <= 'z'; c++) {
        if (arr[c-'a'] > arr[mxc-'a']) {
            mxc = c;
        }
    }
    string buf = "";
    int rst = 1;
    for (char c : s) {
        if (c == mxc) {
            rst += solve(buf);
            buf.clear();
        } else {
            buf.push_back(c);
        }
    }
    if (!buf.empty()) {
        rst += solve(buf);
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << solve(s) << endl;
    return 0;
}