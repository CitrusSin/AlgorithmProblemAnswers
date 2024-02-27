#include <bits/stdc++.h>

using namespace std;

int main() {
    array<array<int, 3>, 3> ans;
    ans[0][0] = 4;
    ans[0][1] = 4;
    ans[0][2] = 6;
    ans[1][0] = 3;
    ans[1][1] = 3;
    ans[1][2] = 4;
    ans[2][0] = 2;
    ans[2][1] = 2;
    ans[2][2] = 2;

    int x, y;
    cin >> x >> y;
    cout << ans[x][y] << '\n';
}