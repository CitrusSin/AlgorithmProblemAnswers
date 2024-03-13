#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, int> sim, rsim;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sim[0] = a[0];
    rsim[a[0]] = 0;
    for (int i=1; i<n; i++) {
        sim[a[i-1]] = a[i];
        rsim[a[i]] = a[i-1];
    }
    sim[a[n-1]] = -1;
    rsim[-1] = a[n-1];

    int q;
    cin >> q;
    while (q--) {
        int opr;
        cin >> opr;
        if (opr == 1) {
            int x, y;
            cin >> x >> y;
            int z = sim[x];
            sim[x] = y;
            sim[y] = z;
            rsim[z] = y;
            rsim[y] = x;
        } else if (opr == 2) {
            int x;
            cin >> x;

            int w = rsim[x];
            int y = sim[x];
            sim[w] = y;
            rsim[y] = w;
            sim.erase(x);
            rsim.erase(x);
        }
    }

    int u = 0;
    while (sim[u] != -1) {
        u = sim[u];
        cout << u;
        if (sim[u] != -1) cout << ' ';
    }
    cout << '\n';

    return 0;
}