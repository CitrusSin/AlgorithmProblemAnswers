#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    int matrix[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }

    long long prefix[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            long long val = 0;
            if (i > 0) {
                val += prefix[i-1][j];
            }
            if (j > 0) {
                val += prefix[i][j-1];
            }
            if (i > 0 && j > 0) {
                val -= prefix[i-1][j-1];
            }
            prefix[i][j] = val + matrix[i][j];
        }
    }

    long long maxval = 0;
    int maxx = 0, maxy = 0;

    for (int x=0; x<=n-c; x++) {
        for (int y=0; y<=m-c; y++) {
            long long val = prefix[x+c-1][y+c-1];
            if (x>0) {
                val -= prefix[x-1][y+c-1];
            }
            if (y>0) {
                val -= prefix[x+c-1][y-1];
            }
            if (x>0 && y>0) {
                val += prefix[x-1][y-1];
            }
            if (val > maxval) {
                maxval = val;
                maxx = x;
                maxy = y;
            }
        }
    }

    cout << maxx+1 << " " << maxy+1 << endl;
    return 0;
}