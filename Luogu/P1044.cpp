#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull solve(int n) {
    if (n <= 1) {
        return 1;
    }

    ull seq[n+1];
    seq[0] = 1;
    seq[1] = 1;
    for (int n2 = 2; n2 <= n; n2++) {
        seq[n2] = 0;
        for (int i=0; i<n2; i++) {
            seq[n2] += seq[n2-1-i]*seq[i];
        }
    }

    return seq[n];
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}