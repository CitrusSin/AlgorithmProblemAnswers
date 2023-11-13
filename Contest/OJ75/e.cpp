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

        vector<int> dif(n);
        int last = 0;
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            dif[i] = p-last;
            last = p;
        }

        int cnt = 0;
        for (int i=1; i<n; i++) {
            if (dif[i] < 0) {
                cnt += abs(dif[i]);
                dif[0] += dif[i];
                dif[i] = 0;
            }
        }
        cnt += abs(dif[0]);
        dif[0] = 0;
        cout << accumulate(dif.begin(), dif.end(), 0)+cnt << endl;
    }
    return 0;
}