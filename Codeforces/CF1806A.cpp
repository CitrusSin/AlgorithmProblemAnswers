#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2 || y1-x1 > y2-x2) {
            cout << -1 << endl;
            continue;
        }
        int dify = y2-y1;
        int difx = x1+dify-x2;
        cout << difx + dify << endl;
    }
    return 0;
}