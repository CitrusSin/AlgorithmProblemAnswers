#include <bits/stdc++.h>

using namespace std;

void dfs(
    const vector< vector<int> >& mat,
    vector< vector<char> >& mark,
    int x, int y, int n, int m, int sum,
    const function<void(int)>& callback
) {
    mark[x][y] = true;
    bool found = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (mark[i][j]) continue;
            bool ok = true;
            for (int dx=-1;dx<=1;dx++) {
                for (int dy=-1;dy<=1;dy++) {
                    if ((dx != 0 || dy != 0) && i+dx>=0 && i+dx<n && j+dy>=0 && j+dy<m) {
                        ok &= !mark[i+dx][j+dy];
                        if (!ok) break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                found = true;
                dfs(mat, mark, i, j, n, m, sum+mat[i][j], callback);
            }
        }
    }
    if (!found) {
        callback(sum);
    }
    mark[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > matrix(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> matrix[i][j];
            }
        }

        int max_val = 0;
        vector< vector<char> > mark(n, vector<char>(m, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dfs(matrix, mark, i, j, n, m, matrix[i][j], [&max_val](int s) {
                    max_val = max(max_val, s);
                });
            }
        }

        cout << max_val << endl;
    }
    return 0;
}