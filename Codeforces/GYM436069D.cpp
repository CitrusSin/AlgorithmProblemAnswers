#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
int spec_x[N], spec_y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int len_x = 0, len_y = 0;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (spec_x[x] == 0) len_x+=2;
        if (spec_y[y] == 0) len_y+=2;
        spec_x[x]++;
        spec_y[y]++;
        if (x > 0 && spec_x[x-1] >= spec_x[x]) {
            len_x--;
        } else {
            len_x++;
        }
        if (x < N-1 && spec_x[x+1] >= spec_x[x]) {
            len_x--;
        } else {
            len_x++;
        }
        if (y > 0 && spec_y[y-1] >= spec_y[y]) {
            len_y--;
        } else {
            len_y++;
        }
        if (y < N-1 && spec_y[y+1] >= spec_y[y]) {
            len_y--;
        } else {
            len_y++;
        }
        cout << len_x << " " << len_y << endl;
    }


    return 0;
}