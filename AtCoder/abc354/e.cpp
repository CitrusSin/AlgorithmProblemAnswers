#include <bits/stdc++.h>

using namespace std;

int mex(const set<int>& s) {
    for (int i=0; i<s.size(); i++) {
        if (!s.count(i)) return i;
    }
    return s.size();
}

unordered_map<int, int> sgmem;
vector<int> a, b;
int sg(uint32_t cards) {
    if (sgmem.count(cards)) return sgmem[cards];

    int n = a.size();

    set<int> nxsteps;
    for (int p = 0; p < n; p++) {
        if ((cards & (1u << p)) == 0) continue;
        for (int q = 0; q < n; q++) {
            if (p == q || (cards & (1u << q)) == 0) continue;
            if (a[p] != a[q] && b[p] != b[q]) continue;
            uint32_t c2 = cards;
            c2 -= (1u << p);
            c2 -= (1u << q);
            nxsteps.insert(sg(c2));
        }
    }
    return sgmem[cards] = mex(nxsteps);
}

int main() {
    int n;
    cin >> n;

    a.assign(n, 0);
    b.assign(n, 0);
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    cout << (sg((1 << n) - 1) ? "Takahashi" : "Aoki") << '\n';
    return 0;
}