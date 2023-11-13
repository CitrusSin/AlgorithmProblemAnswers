#include <bits/stdc++.h>

using namespace std;

void solve() {
    int q;
    cin >> q;

    vector<int> arr;
    arr.reserve(q);

    string rst;
    bool flag = false;
    for (int i=0; i<q; i++) {
        int v;
        cin >> v;
        if (flag) {
            if (arr.back() <= v && v <= arr.front()) {
                rst.push_back('1');
                arr.push_back(v);
            } else {
                rst.push_back('0');
            }
        } else {
            if (arr.empty() || v >= arr.back()) {
                rst.push_back('1');
                arr.push_back(v);
            } else if (v <= arr.front()) {
                flag = true;
                rst.push_back('1');
                arr.push_back(v);
            } else {
                rst.push_back('0');
            }
        }
    }

    cout << rst << endl;
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