#include <bits/stdc++.h>

using namespace std;

void gauss(vector<vector<int>>& mat) {
    size_t n = mat.size();

    for (size_t k=0; k<n; k++) {
        if (mat[k][k] == 0) {
            size_t max_row = k;
            for (size_t k2=k+1; k2<n; k2++) {
                if (abs(mat[max_row][k]) < abs(mat[k2][k])) {
                    max_row = k2;
                }
            }
            if (max_row != k) {
                swap(mat[k], mat[max_row]);
            } else {
                continue;
            }
        }
        for (size_t k2 = k+1; k2<n; k2++) {
            if (mat[k2][k] == 1) {
                for (size_t p=k; p<=n; p++) {
                    mat[k2][p] ^= mat[k][p];
                }
            }
        }
    }
    for (size_t k=n-1; k<=n-1; k--) {
        if (mat[k][k] == 0) continue;
        for (size_t k2=0; k2<k; k2++) {
            if (mat[k2][k]) {
                for (size_t p=k; p<=n; p++) {
                    mat[k2][p] ^= mat[k][p];
                }
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n+1, 0));
        for (int i=0; i<n; i++) mat[i][i] = 1;
        for (int i=0; i<n; i++) {
            cin >> mat[i][n];
        }
        for (int i=0; i<n; i++) {
            int p;
            cin >> p;
            mat[i][n] ^= p;
        }

        int a, b;
        while (cin >> a >> b, a > 0 && b > 0) {
            mat[b-1][a-1] = 1;
        }
        gauss(mat);

        bool hs = true;
        int free_count = 0;
        for (int i=0; i<n; i++) {
            bool az = true;
            for (int j=0; j<n; j++) {
                if (mat[i][j] != 0) {
                    az = false;
                    break;
                }
            }
            if (az && mat[i][n]) {
                hs = false;
                break;
            } else {
                free_count += mat[i][i] == 0;
            }
        }
        if (hs) {
            cout << (1 << free_count) << endl;
        } else {
            cout << "Oh,it's impossible~!!" << endl;
        }
    }
    return 0;
}