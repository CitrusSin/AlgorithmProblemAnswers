#include <bits/stdc++.h>
using namespace std;

struct item {
    int origin;
    int value;
    item(int ori, int val) {
        origin = ori;
        value = val;
    }
    bool operator<(const item& x) const {
        return value < x.value;
    }
    bool operator>(const item& x) const {
        return value > x.value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> res, groups(n, 0);
    priority_queue<item, vector<item>, greater<item>> pq;
    res.reserve(n);
    for (int i=0; i<n; i++) {
        pq.emplace(i, a[i]+b[groups[i]++]);
    }
    for (int i=0; i<n; i++) {
        item s = pq.top();
        pq.pop();
        res.push_back(s.value);
        pq.emplace(s.origin, a[s.origin]+b[groups[s.origin]++]);
    }

    bool b_flag = true;
    for (int r : res) {
        if (b_flag) {
            b_flag = false;
        } else {
            cout << ' ';
        }
        cout << r;
    }
    cout << endl;
    return 0;
}