#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t x;
    cin >> x;

    if (x < 0) {
        x /= 10;
    } else {
        x = (x / 10) + (x % 10 != 0);
    }

    cout << x << '\n';
    return 0;
}