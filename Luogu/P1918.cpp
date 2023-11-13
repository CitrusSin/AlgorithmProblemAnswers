#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, int> a;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        a[p] = i+1;
    }

    int q;
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        cout << (a.count(p)?a[p]:0) << endl;
    }
    return 0;
}