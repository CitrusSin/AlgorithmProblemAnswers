#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int y1;
        cin >> y1;
        int n;
        cin >> n;
        vector<int> skips(n);
        for (int i=0; i<n; i++) {
            cin >> skips[i];
        }

        int y2;
        cin >> y2;

        int tms = 0, spc = 0;
        for (int y = y1; y<y2; y++) {
            if (spc >= n || y != skips[spc]) tms++; else spc++;
        }
        cout << tms+1 << endl;
    }
    return 0;
}