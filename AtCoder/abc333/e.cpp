#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    arr.reserve(n);
    for (int i=0; i<n; i++) {
        int t, x;
        cin >> t >> x;
        arr.emplace_back(t, x);
    }

    multiset<int> backpack;
    size_t max_cap = 0;
    vector<int> operate(n, 0);
    for (int i = n-1; i >= 0; i--) {
        pair<int, int>& pr = arr[i];
        if (pr.first == 2) {
            backpack.insert(pr.second);
            max_cap = max(max_cap, backpack.size());
        } else if (pr.first == 1) {
            if (backpack.count(pr.second) != 0) {
                backpack.extract(pr.second);
                operate[i] = 1;
            }
        }
    }

    if (!backpack.empty()) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << max_cap << endl;
        bool flag = false;
        for (int i=0; i<operate.size(); i++) {
            if (arr[i].first != 1) continue;
            if (!flag) flag = true; else cout << ' ';
            cout << operate[i];
        }
        cout << endl;
    }

    return 0;
}