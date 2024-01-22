#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> ct;

    string s;
    cin >> s;

    for (char c : s) ct[c]++;
    for (char c : string("xiaohong")) ct[c]--;

    string s2 = "xiaohong";
    for (auto [ch, cnt] : ct) {
        for (int i=0; i<cnt; i++) {
            s2.push_back(ch);
        }
    }

    cout << s2 << endl;
}