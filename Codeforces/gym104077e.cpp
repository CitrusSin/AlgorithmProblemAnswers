#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 cvt(const vector<int>& l) {
    i64 val = 0;
    for (int v : l) {
        val *= 3;
        val += v;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        i64 l, r;
        cin >> l >> r;
        int ll = 0, lr = 0;
        i64 l2 = l, r2 = r;
        while (l2) {
            ll++;
            l2 /= 3;
        }
        while (r2) {
            lr++;
            r2 /= 3;
        }

        int oprc = 0;
        for (int k=lr; k>=ll; k--) {
            vector<int> l3(k, 2);
            int oprc2 = 3 * k;
            bool flag = false;
            if (cvt(l3) >= l && cvt(l3) <= r) oprc = max(oprc, oprc2);
            for (int i=0; i<k && cvt(l3) > r; i++) {
                l3[i]--;
                oprc2--;
                if (i != 0 && cvt(l3) > r) {
                    l3[i]--;
                    oprc2--;
                }
                if (cvt(l3) < l) {
                    l3[i]++;
                    oprc2++;
                }
                if (cvt(l3) >= l && cvt(l3) <= r) oprc = max(oprc, oprc2);
            }
        }
        
        cout << oprc << '\n';
    }
    return 0;
}