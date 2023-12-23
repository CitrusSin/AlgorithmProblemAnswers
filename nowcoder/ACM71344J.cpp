#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using i64 = int64_t;

void solve() {
    int n, k;
    cin >> n >> k;

    i64 mod = 1;
    for (int i=0; i<k; i++) {
        mod *= 10;
    }

    vector<i64> ps;
    i64 pr = 1;
    for (i64 i=1; i<=n; i++) {
        pr *= i;
        while (pr % 10 == 0) pr /= 10;
        pr %= mod;
        ps.push_back(pr);
    }

    __int128 ans = 1;
    for (i64 v : ps) {
        ans *= v;
        while (ans % 10 == 0) ans /= 10;
        ans %= mod;
    }

    stringstream ss;
    ss << (i64)ans;
    string s;
    ss >> s;
    for (int i=0; i<(k-s.size()); i++) cout << '0';
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}