#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

void solve() {
    int n;
    cin >> n;
    int a = INF, b = INF, c = INF;
    for (int i=0; i<n; i++) {
        int m;
        string type;
        cin >> m >> type;
        if (type == "10") {
            a = min(a, m);
        } else if (type == "01") {
            b = min(b, m);
        } else if (type == "11") {
            c = min(c, m);
        }
    }
    int res = min(a+b, c);
    if (a == INF || b == INF) res = c;
    if (res == INF) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
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