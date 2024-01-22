#include <bits/stdc++.h>

using namespace std;

int main() {
    int state = 0;

    string s;
    cin >> s;

    for (char c : s) {
        int v = c - 'A';
        if (state == -1) break;
        if (v == state) continue;
        if (v > state) {
            state++;
        } else {
            state = -1;
        }
    }

    cout << (state < 3 && state != -1 ? "Yes" : "No") << endl;
}