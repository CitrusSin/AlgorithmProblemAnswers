#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, int> walls;
    for (int i=1; i<=n; i++) {
        cin >> walls[i];
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x;
            if (!walls.count(p)) continue;

            walls[p] -= x;
            if (walls[p] <= 0) {
                walls.erase(p);
            }
        } else if (op == 2) {
            int p;
            cin >> p;
            auto it = walls.lower_bound(p);
            int pos = it == walls.end() ? n : it->first;
            cout << pos << '\n';
        }
    }
    return 0;
}