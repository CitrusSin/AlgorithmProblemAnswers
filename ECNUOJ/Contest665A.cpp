#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    return f(x/2)+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}