#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    list<int> lp;
    for (int i=0; i<n; i++) {
        lp.push_back(i+1);
    }

    auto iter = lp.begin();
    while (!lp.empty()) {
        for (int i=1; i<m; i++) {
            if (iter == lp.end()) {
                iter = lp.begin();
            }
            iter++;
        }
        if (iter == lp.end()) {
            iter = lp.begin();
        }
        cout << *iter << ' ';
        iter = lp.erase(iter);
    }
    return 0;
}