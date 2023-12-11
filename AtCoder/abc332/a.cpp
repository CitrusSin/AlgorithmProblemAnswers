#include <iostream>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, s, k;
    cin >> n >> s >> k;

    i64 total = 0;
    for (i64 i=0; i<n; i++) {
        i64 p, q;
        cin >> p >> q;
        total += p * q;
    }

    if (total < s) total += k;

    cout << total << endl;
    return 0;
}