#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;

        int min_time = 0, max_time = 0;
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            int mi = min(p, l-p);
            int ma = max(p, l-p);
            if (mi > min_time) {
                min_time = mi;
            }
            if (ma > max_time) {
                max_time = ma;
            }
        }

        cout << min_time << " " << max_time << endl;
    }
    return 0;
}