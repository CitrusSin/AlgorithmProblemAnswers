#include <bits/stdc++.h>

using namespace std;
using u32 = uint32_t;

const u32 INF = numeric_limits<u32>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> ts(n);
    for (int i=0; i<n; i++) {
        cin >> ts[i];
    }

    vector<vector<vector<u32>>> mat(
        n+1,
        vector<vector<u32>>(
            n, 
            vector<u32>(
                n, INF
            )
        )
    );
    for (int i=0; i<n; i++) {
        for (int j=0; j<=n; j++) {
            mat[j][i][i] = 0;
        }
    }
    while (m--) {
        int i, j, w;
        cin >> i >> j >> w;
        mat[0][i][j] = mat[0][j][i] = w;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (mat[k][i][k] != INF && mat[k][k][j] != INF) {
                    mat[k+1][i][j] = min(mat[k][i][j], mat[k][i][k] + mat[k][k][j]);
                } else {
                    mat[k+1][i][j] = mat[k][i][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y, t;
        cin >> x >> y >> t;

        int k = upper_bound(ts.begin(), ts.end(), t) - ts.begin();
        if (x >= k || y >= k || mat[k][x][y] == INF) {
            cout << -1 << endl;
        } else {
            cout << mat[k][x][y] << endl;
        }
    }
    return 0;
}