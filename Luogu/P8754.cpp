#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    u64 n;
    cin >> n;
    u64 n0 = n;

    u64 res = 1;
    for (u64 i=2; i*i<=n; i++) {
        if (n == 1) break;
        int cnt = 0;
        while (n%i==0) {
            n /= i;
            cnt++;
        }
        if (cnt%2==1) {
            res *= i;
        }
    }
    res *= n;
    cout << res << endl;
    return 0;
}