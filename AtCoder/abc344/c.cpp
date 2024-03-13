#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {

    set<i64> a, b, c;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int u;
        cin >> u;
        a.insert(u);
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int u;
        cin >> u;
        b.insert(u);
    }

    int l;
    cin >> l;
    for(int i=0; i<l; i++) {
        int u;
        cin >> u;
        c.insert(u);
    }

    set<i64> sp;
    for (i64 p : a) {
        for (i64 q : b) {
            sp.insert(p+q);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        i64 x;
        cin >> x;
        
        bool flag = false;
        for (i64 s : c) {
            i64 rp = x - s;
            if (sp.count(rp)) {
                flag = true;
                break;
            }
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }
}