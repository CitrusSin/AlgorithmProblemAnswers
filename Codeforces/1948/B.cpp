#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    list<int> arr;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        arr.push_back(p);
    }
    arr.reverse();

    int last = -1;
    auto lastit = arr.begin();
    for (auto ri = arr.begin(); ri != arr.end(); ri++) {
        if (last == -1) {
            last = *ri;
            lastit = ri;
            continue;
        }
        int pres = *ri;
        if (pres <= last) {
            last = pres;
            lastit = ri;
            continue;
        }
        if (pres < 10) {
            cout << "NO\n";
            return;
        }
        ri = arr.erase(ri);

        int p2 = pres;
        auto it2 = ri;
        while (p2 > 0) {
            int u = p2 % 10;
            p2 /= 10;
            arr.insert(it2, u);
        }

        ri = lastit;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}