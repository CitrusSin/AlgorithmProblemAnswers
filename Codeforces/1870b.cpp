#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int suma = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        suma ^= p;
    }

    int min_ans = suma, max_ans = suma;

    int b = 0;
    for (int i=0; i<m; i++) {
        int p;
        cin >> p;
        b |= p;
        /*
        int rst = 0;
        if (n % 2 == 0) {
            rst = suma & (~b);
        } else {
            rst = suma | b;
        }

        min_ans = min(min_ans, rst);
        max_ans = max(max_ans, rst);
        */
    }

    if (n % 2 == 0) {
        min_ans = suma & (~b);
    } else {
        max_ans = suma | b;
    }
    cout << min_ans << ' ' << max_ans << '\n';
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