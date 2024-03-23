#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> stat;
    for (char c : s) {
        stat[c]++;
    }

    uint64_t total = 0;
    for (char c : s) {
        total += s.size() - stat[c];
    }
    total /= 2;

    for (auto [c, t] : stat) {
        if (t > 1) {
            total += 1;
            break;
        }
    }

    cout << total << '\n';
    return 0;
}