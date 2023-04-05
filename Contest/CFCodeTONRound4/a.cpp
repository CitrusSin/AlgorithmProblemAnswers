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

        bool flag = false;
        for (int i=1; i<=n; i++) {
            int k;
            cin >> k;
            if (k <= i) flag = true;
        }

        cout << (flag?"YES":"NO") << endl;
    }
    return 0;
}