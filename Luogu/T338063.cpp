#include <bits/stdc++.h>

using namespace std;

bool mark[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        mark[x][y] = true;
    }

    int64_t sum = 0;
    // dif = x-y
    for (int dif = -499; dif <= 499; dif++) {
        int64_t psum = 0;
        int plen = 0;
        for (int x = max(0, dif); x<min(500, 500+dif); x++) {
            int y = x-dif;
            if (mark[x][y]) {
                plen++;
            } else if (plen > 0) {
                psum += plen * (int64_t)(plen+1);
                plen = 0;
            }
        }
        if (plen != 0) psum += plen * (int64_t)(plen+1);
        sum += psum;
    }

    cout << sum << endl;
    return 0;
}