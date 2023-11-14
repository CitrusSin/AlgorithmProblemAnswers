#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int v = 0;
    for (char c : s) {
        int d = c - '0';

        v = gcd(v, d);
        if (v == 1) break;
    }
    cout << v << endl;
    return 0;
}