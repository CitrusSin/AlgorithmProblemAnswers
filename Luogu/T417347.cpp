#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> img(n, vector<char>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> img[i][j];
        }
    }

    for (int i=0; i<k*n; i++) {
        for (int j=0; j<k*m; j++) {
            cout << img[i/k][j/k];
        }
        cout << endl;
    }
    return 0;
}