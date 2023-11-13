#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, vector<int>> query_map;

    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n; i++) {
        query_map[arr[i]].push_back(i);
    }

    int mex = 0;
    auto iter = query_map.begin();
    for (iter = query_map.begin(); iter != query_map.end(); iter++) {
        const auto& p = *iter;
        if (p.first == mex) {
            mex++;
        } else {
            break;
        }
    }
        
    if (mex == 0) {
        cout << "Yes" << endl;
        return;
    }
    if (mex == n) {
        cout << "No" << endl;
        return;
    }

    vector<int>& p = query_map[mex+1];

    if (p.empty()) {
        cout << "Yes" << endl;
        return;
    }
    int l = p.front(), r = p.back();
    for (int i=l; i<=r; i++) {
        if (arr[i] < mex) {
            query_map[arr[i]].pop_back();
            if (query_map[arr[i]].empty()) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}