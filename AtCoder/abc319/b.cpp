#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<char> chs(n+1, '-');
    for (int i=0; i<=n; i++) {
        for (int j=1; j<=9; j++) {
            if (n % j == 0) {
                int r = n/j;
                if (i % r == 0) {
                    chs[i] = j | 0x30;
                    break;
                }
            }
        }
    }

    for (int i=0; i<=n; i++) {
        cout << chs[i];
    }
    cout << endl;
    return 0;
}