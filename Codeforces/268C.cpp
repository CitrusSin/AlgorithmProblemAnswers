#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt = min(n, m) + 1;
    if (n == 0 && m == 0) cnt = 0;
    int x=0, y=min(n, m);
    cout << cnt << endl;
    for (int i=0; i<cnt; i++) {
        cout << x << ' ' << y << endl;
        x++;
        y--;
    }
    return 0;
}