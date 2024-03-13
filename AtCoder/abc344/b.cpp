#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> vals;

    int p;
    while (cin >> p, p != 0) {
        vals.push(p);
    }
    vals.push(0);

    while (!vals.empty()) {
        int p2 = vals.top();
        vals.pop();
        cout << p2 << '\n';
    }
    return 0;
}