#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> values(1, 0);
    int n;
    string s;
    cin >> n;
    cin >> s;

    for (char c : s) {
        if (c == 'o') {
            values.back()++;
        } else {
            values.push_back(0);
        }
    }
    if (values.size() == 1) {
        cout << "-1" << endl;
    } else {
        int mxv = 0;
        for (int i : values) mxv = max(mxv, i);
        cout << (mxv == 0 ? -1 : mxv) << endl;
    }
    return 0;
}