#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;

    string party;
    cin >> party;

    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        // Drop x and y
    }

    int tm = (m - n + 1) % k;
    char mk = party[tm] == '1' ? '2' : '1';
    cout << mk << '\n';
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