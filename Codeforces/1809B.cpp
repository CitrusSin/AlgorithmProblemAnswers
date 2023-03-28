#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 test_sqrt(u64 s) {
    u64 x = 1;
    for (;;) {
        u64 x2 = x+s/x;
        if (s%x) x2++;
        u64 x3 = x2/2;
        if (x2%2) x3++;
        if (x3 == x) break;
        x = x3;
    }
    while ((x-1)*(x-1)>=s) x--;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        u64 n;
        cin >> n;
        u64 r = test_sqrt(n)-1;
        cout << r << endl;
    }
    return 0;
}