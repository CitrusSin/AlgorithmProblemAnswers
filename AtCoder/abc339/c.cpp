#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    i64 n;
    cin >> n;

    vector<i64> a(n);
    for (i64 i=0; i<n; i++) cin >> a[i];

    i64 minpas = 0, current = 0;
    for (i64 i=0; i<n; i++) {
        current += a[i];
        minpas = min(minpas, current);
    }

    i64 ans = current - minpas;
    cout << ans << endl;
    return 0;
}