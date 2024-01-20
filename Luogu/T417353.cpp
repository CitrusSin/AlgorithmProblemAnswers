#include <bits/stdc++.h>

using namespace std;
using i64 = uint64_t;

int main() {
    i64 n, q;
    cin >> n >> q;

    i64 tot = 0;
    while (q--) {
        i64 k;
        cin >> k;
        if (((n >> (k-1)) & 1) == 0) {
            i64 p = ~n & ~(~0ull << (k-1));
            p++;
            tot += p;
            n += p;
        }
    }

    cout << tot << endl;
    return 0;
}