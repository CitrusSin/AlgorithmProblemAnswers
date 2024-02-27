#include <bits/stdc++.h>

using namespace std;

array<int, 10000> sts;
array<bool, 10000> stk;
int search(int a1, int a2, int b1, int b2, int p, int q) {
    if (p >= a1) return 1;
    if (a2 - p > a1 + q) return -1;
    
    int pos = (a1-1) * 100 + a2-1;
    if (sts[pos] != -2) {
        return sts[pos];
    }

    if (stk[pos]) {
        return -1;
    }
    stk[pos] = true;

    int brought = a1 - a2 + q;
    brought = min(p, brought);

    int ms1 = 0, ms2 = 0;
    if (brought < 0) {
        ms2 = -brought;
    } else {
        ms1 = brought;
    }
    int space = p - ms1 - ms2;
    ms1 += (space / 2);
    ms2 += (space / 2);
    ms2 += p - ms1 - ms2;

    int ans = numeric_limits<int>::max();
    for (int s2 = ms2; s2 <= p; s2++) {
        int s1 = p - s2;
        int min_bb = max(0, b2 + s2 - b1 - s1 - q);
        if (b1 + s1 == 0) min_bb = 0;
        int max_bb = min(p, b2 + s2);
        for (int bb = min_bb; bb <= max_bb; bb++) {
            int na1 = a1 - s1, na2 = a2 - s2 + bb;
            int nb1 = b1 + s1, nb2 = b2 + s2 - bb;
            if (s1 == 0 && s2 == bb) continue;
            int pans = search(na1, na2, nb1, nb2, p, q);
            if (pans != -1) {
                ans = min(ans, pans + 2);
            }
        }
    }

    if (ans == numeric_limits<int>::max()) ans = -1;

    stk[pos] = false;
    sts[pos] = ans;
    return ans;
}

int main() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    
    sts.fill(-2);
    stk.fill(false);
    int ans = search(x, y, 0, 0, p, q);
    cout << ans << '\n';
}