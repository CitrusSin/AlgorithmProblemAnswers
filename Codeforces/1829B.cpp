#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int max_cnt = 0, cnt = 0;
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            if (p == 0) {
                cnt++;
            } else {
                max_cnt = max(max_cnt, cnt);
                cnt = 0;
            }
        }
        max_cnt = max(max_cnt, cnt);
        cout << max_cnt << endl;
    }
    return 0;
}