#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) {
        cout << "0" << endl;
    } else if (p.size() == 2) {
        int df = p[1]-p[0];
        if (df % 2 == 0) df /= 2;
        cout << df << endl;
    } else if (p.size() == 3) {
        int r1 = p[1]-p[0], r2 = p[2]-p[1];
        if (r1 == r2) {
            cout << r1 << endl;
        } else {
            cout << "-1" << endl;
        }
    } else {
        cout << "-1" << endl;
    }
    return 0;
}