#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r;
    cin >> r;
    vector<vector<int>> tri(r);

    for (int i=0; i<r; i++) {
        for (int j=0; j<i+1; j++) {
            int p;
            cin >> p;
            tri[i].push_back(p);
        }
    }

    for (int i=r-2; i>=0; i--) {
        for (int j=0; j<i+1; j++) {
            tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
        }
    }

    cout << tri[0][0] << endl;
    return 0;
}