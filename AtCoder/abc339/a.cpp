#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> qc;
    for (auto it = s.rbegin(); it != s.rend() && *it != '.'; it++) {
        qc.push(*it);
    }

    string sc;
    while (!qc.empty()) {
        sc.push_back(qc.top());
        qc.pop();
    }

    cout << sc << endl;
    return 0;
}