#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a<b) {
            if ((a-b)%4==0) {
                cout << 3 << endl;
            } else {
                cout << ((a-b)%2==0?2:1) << endl;
            }
        } else if (a>b) {
            cout << ((a-b)%2==0?1:2) << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}