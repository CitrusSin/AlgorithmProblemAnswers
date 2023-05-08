#include <bits/stdc++.h>

using namespace std;

bool zero(double x) {
    return abs(x) < 1e-6;
}

void gauss(vector<vector<double>>& mat) {
    size_t n = mat.size();

    for (size_t k=0; k<n; k++) {
        if (zero(mat[k][k])) {
            int max_id = k;
            for (size_t i=k+1; i<n; i++) {
                if (abs(mat[i][k]) > abs(mat[max_id][k])) {
                    max_id = i;
                }
            }
            if (max_id != k) swap(mat[max_id], mat[k]);
            if (zero(mat[k][k])) {
                continue;
            }
        }

        double co = 1.0/mat[k][k];
        for (size_t i = k; i <= n; i++) {
            mat[k][i] *= co;
        }

        for (size_t l = k+1; l<n; l++) {
            double cp = mat[l][k];
            if (zero(cp)) continue;
            for (size_t i = k; i<=n; i++) {
                mat[l][i] -= cp * mat[k][i];
            }
        }
    }

    for (size_t k=n-1; k<=n-1; k--) {
        for (size_t l=0; l<k; l++) {
            double co = mat[l][k];
            for (size_t i=k; i<=n; i++) {
                mat[l][i] -= co * mat[k][i];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(2);

    int n;
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n+1, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<=n; j++) {
            cin >> mat[i][j];
        }
    }

    gauss(mat);

    bool hs = true;
    bool solve_space = false;
    for (int i=0; i<n; i++) {
        if (zero(mat[i][i])) {
            solve_space = true;

            bool az = true;
            for (int j=0; j<n; j++) {
                if (mat[i][j] != 0) {
                    az = false;
                    break;
                }
            }
            if (az && mat[i][n]) {
                hs = false;
                solve_space = false;
                break;
            }
        }
    }

    if (hs && !solve_space) {
        for (int i=0; i<n; i++) {
            cout << "x" << (i+1) << "=" << mat[i][n] << endl;
        }
    } else if (hs) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}