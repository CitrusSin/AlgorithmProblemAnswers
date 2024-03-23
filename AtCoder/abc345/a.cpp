#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    size_t n = s.size();

    bool flag = true;
    if (s[0] != '<') flag = false;
    if (s[n-1] != '>') flag = false;
    if (n <= 2) flag = false;
    for (size_t i=1; i<n-1; i++) {
        if (s[i] != '=') flag = false;
    }

    cout << (flag ? "Yes" : "No") << '\n';
    return 0;
}