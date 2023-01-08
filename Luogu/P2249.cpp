#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, int> query_map;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (query_map.count(p) == 0) {
            query_map[p] = i;
        }
    }

    for (int i=0; i<m; i++) {
        int q;
        cin >> q;
        if (query_map.count(q)) {
            cout << query_map[q]+1;
        } else {
            cout << "-1";
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}