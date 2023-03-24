#include <bits/stdc++.h>
using namespace std;

char space[53][53];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    while (cin.get() != '\n');

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            space[i][j] = cin.get();
        }
        cin.get();
    }

    for (int j=0; j<m; j++) {
        int t_pos = n-1;
        for (int i=n-1; i>=0; i--) {
            if (space[i][j] == 'o') {
                t_pos = i-1;
                while (t_pos >= 0 && space[t_pos][j] != '.') t_pos--;
                i = t_pos;
                continue;
            } else if (space[i][j] == '*') {
                // swap
                char p = space[i][j];
                space[i][j] = space[t_pos][j];
                space[t_pos][j] = p;

                while (t_pos >= 0 && space[t_pos][j] != '.') t_pos--;
                i = min(i, t_pos);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout.put(space[i][j]);
        }
        cout.put('\n');
    }
    return 0;
}