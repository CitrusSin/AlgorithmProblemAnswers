#include <bits/stdc++.h>

using namespace std;

template <typename T>
void output(const vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
}

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> a, b;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        a[p]++;
    }
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        b[p]++;
    }

    vector<int> l, r;

    k*=2;
    int u = 1;
    while (u <= n && k > 0) {
        if (!a.count(u) || a[u] == 2) {
            u++;
            continue;
        }
        l.push_back(u);
        r.push_back(u);
        a.erase(u);
        b.erase(u);
        k--;
        u++;
    }
    if (k > 0 && k % 2 == 1) {
        l.pop_back();
        r.pop_back();
        k++;
    }
    while (k > 0) {
        auto [k1, v1] = *a.begin();
        auto [k2, v2] = *b.begin();
        a.erase(k1);
        b.erase(k2);
        l.push_back(k1);
        l.push_back(k1);
        r.push_back(k2);
        r.push_back(k2);
        k -= 2;
    }

    output(l);
    output(r);
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