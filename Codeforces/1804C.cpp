#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        i64 n, x, p;
        cin >> n >> x >> p;

        i64 r = (n-x)%n;
        bool flag = false;

        i64 upper = min(2*n, p);
        for (i64 f=1; f<=upper; f++) {
            if ((f*(f+1)/2)%n==r) {
                flag = true;
                break;
            }
        }
        cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}