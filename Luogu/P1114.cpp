#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (p == 0) vals[i] = -1; else vals[i] = 1;
    }

    unordered_map<int, int> query_map;
    query_map[vals[0]] = 0;

    int mxl = 0;
    for (int i=1; i<n; i++) {
        vals[i] += vals[i-1];
        if (vals[i] == 0) {
            mxl = i+1;
        } else {
            if (!query_map.count(vals[i])) {
                query_map[vals[i]] = i;
            } else {
                mxl = max(mxl, i-query_map[vals[i]]);
            }
        }
    }

    cout << mxl << endl;
    return 0;
}