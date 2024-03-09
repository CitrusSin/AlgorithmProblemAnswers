#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    string t;
    int stg = 0;
    for (char c : s) {
        if (c == '|') {
            stg++;
            continue;
        }
        if (stg % 2 == 0) {
            t.push_back(c);
        }
    }

    cout << t << '\n';
}