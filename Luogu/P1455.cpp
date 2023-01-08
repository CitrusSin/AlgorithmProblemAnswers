#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int dsg[N], dsc[N], dsv[N];

static inline void init() {
    memset(dsg, 0xff, sizeof(dsg));
}

int dshead(int x) {
    if (dsg[x] == -1) {
        return x;
    } else {
        int res = dshead(dsg[x]);
        dsg[x] = res;
        return res;
    }
}

void dsmerge(int a, int b) {
    a = dshead(a);
    b = dshead(b);
    if (a != b) {
        dsc[a] += dsc[b];
        dsv[a] += dsv[b];
        dsg[b] = a;
    }
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, w;
    cin >> n >> m >> w;
    for (int i=0; i<n; i++) {
        cin >> dsc[i] >> dsv[i];
    }

    int gc = n-m;

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        dsmerge(u-1, v-1);
    }

    vector<int> costs, values;
    costs.reserve(gc);
    values.reserve(gc);

    for (int i=0; i<n; i++) {
        if (dsg[i] == -1) {
            costs.push_back(dsc[i]);
            values.push_back(dsv[i]);
        }
    }

    vector<int> dpa(w+1, 0);
    for (int i=0; i<gc; i++) {
        for (int c=w; c>=0; c--) {
            if (c >= costs[i]) {
                dpa[c] = max(dpa[c], dpa[c-costs[i]]+values[i]);
            }
        }
    }
    cout << dpa[w] << endl;
    return 0;
}