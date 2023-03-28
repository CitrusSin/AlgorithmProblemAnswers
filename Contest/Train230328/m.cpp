#include <bits/stdc++.h>

using namespace std;

int n, m;
const bool templ[6][6] = 
{{1, 1, 1, 1, 1, 1},
 {1, 1, 0, 0, 1, 1},
 {1, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 1},
 {1, 1, 0, 0, 1, 1},
 {1, 1, 1, 1, 1, 1}};
bool a[1000][1000], cirs[1000][1000];

bool detect(int x, int y) {
    if (x+6>n || y+6>m) return false;
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            if (a[x+i][y+j] != templ[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c=0, s=0;

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string line;
        cin >> line;
        for (int j=0; j<m; j++) {
            char c = line[j];
            a[i][j] = c == '#';
        }
    }

    for (int i=0; i<n-7; i++) {
        for (int j=0; j<m-7; j++) {
            if (!cirs[i][j] && detect(i, j)) {
                cirs[i][j] = true;
                if (i+7<n+7 && detect(i+7, j)) {
                    cirs[i+7][j] = true;
                    c++;
                } else if (j+7<m+7 && detect(i, j+7)) {
                    cirs[i][j+7] = true;
                    c++;
                } else {
                    s++;
                }
            }
        }
    }

    cout << c << " " << s << endl;
    return 0;
}