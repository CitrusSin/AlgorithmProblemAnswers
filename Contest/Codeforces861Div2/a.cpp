#include <bits/stdc++.h>

using namespace std;

int lucky_value(int x) {
    char buf[34];
    sprintf(buf, "%d", x);
    char minc = '9', maxc = '0';
    for (char* p = buf; *p >= '0' && *p <= '9'; p++) {
        if (*p > maxc) maxc = *p;
        if (*p < minc) minc = *p;
    }
    return maxc-minc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int dif = r-l;

        int luckiest = 0, luckiest_value = 0;
        for (int i=l; i<=l+dif; i++) {
            int lv = lucky_value(i);
            if (lv > luckiest_value) {
                luckiest_value = lv;
                luckiest = i;
            }
            if (luckiest_value == 9) break;
        }
        if (luckiest == 0) luckiest = l;

        cout << luckiest << endl;
    }
    return 0;
}