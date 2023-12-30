#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    // u + v = n
    // u(u+1)/2 - v = m
    // n + m == u(u+3)/2 =  u^2+3u
    // u^2+3u-2(n+m) = 0
    // delta = sqrt(9 + 8(n+m))
    // u = -3 + sqrt(9+8(n+m)) / 2

    i64 n, m;
    cin >> n >> m;

    i64 delta = sqrt(9 + 8*(n+m));
    i64 u = (delta - 3) / 2;
    i64 v = n - u;

    cout << v << endl;

    return 0;
}