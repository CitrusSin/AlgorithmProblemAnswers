#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

struct item {
    u64 s;
    u64 a;
    u64 e;
    item(u64 s, u64 a, u64 e) : s(s), a(a), e(e) {}
    u64 total() const {
        return s+a+e;
    }
    u64 message() const {
        return s+a;
    }
    bool operator<(const item& i2) const {
        return total() < i2.total();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<item> items;
    items.reserve(n);
    for (int i=0; i<n; i++) {
        int s, a, e;
        cin >> s >> a >> e;
        items.emplace_back(s, a, e);
    }

    sort(items.begin(), items.end());

    u64 total_time = 0;
    u64 tick_sum = 0;
    for (item& it : items) {
        tick_sum += total_time + it.message();
        total_time += it.total();
    }
    cout << tick_sum << endl;
    return 0;
}