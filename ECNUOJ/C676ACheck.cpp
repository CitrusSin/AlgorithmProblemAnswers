#include <bits/stdc++.h>

using namespace std;

char model[4][4] = {
    {'1', '1', '0', '0'},
    {'1', '0', '1', '0'},
    {'0', '1', '0', '1'},
    {'0', '0', '1', '1'}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if ((n > 4 || m > 4) && n != 2 && m != 2) {
            cout << "No" << endl;
        } else if (n <= 4 && m <= 4) {
            cout << "Yes" << endl;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    cout << model[i][j];
                }
                cout << endl;
            }
        } else if (n == 2) {
            cout << "Yes" << endl;
            for (int i=0; i<m; i++) {
                cout << '1';
            }
            cout << endl;
            for (int i=0; i<m; i++) {
                cout << '0';
            }
            cout << endl;
        } else if (m == 2) {
            cout << "Yes" << endl;
            for (int i=0; i<n; i++) {
                cout << "10" << endl;
            }
        }
    }
    return 0;
}