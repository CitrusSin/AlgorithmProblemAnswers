#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class dsu {
private:
    vector<int> values;
public:
    explicit dsu(int n) : values(n, -1) {}

    int head(int x) {
        if (values[x] == -1) return x;
        return values[x] = head(values[x]);
    }

    void merge(int x, int y) {
        x = head(x);
        y = head(y);

        if (y != x) values[y] = x;
    }

    bool test(int x, int y) {
        x = head(x);
        y = head(y);
        return x == y;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<tuple<int, int, bool>> recs(n);

    while (n--) {
        int x, y;
        bool z;
        cin >> x >> y >> z;
        x--, y--;
        recs.emplace_back(x, y, z);
    }

    array<int, 3> t1{1, 2, 3}, t2{1, 1, 2}, t3{1, 2, 2}, t4{1, 1, 1};
    bool ans = false;
    do {
        bool flag = true;
        for (const auto& p : recs) {
            if ((t1[get<0>(p)] < t1[get<1>(p)]) != get<2>(p)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = true;
        }
    } while (!ans && next_permutation(t1.begin(), t1.end()));
    do {
        bool flag = true;
        for (const auto& p : recs) {
            if ((t2[get<0>(p)] < t2[get<1>(p)]) != get<2>(p)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = true;
        }
    } while (!ans && next_permutation(t2.begin(), t2.end()));
    do {
        bool flag = true;
        for (const auto& p : recs) {
            if ((t3[get<0>(p)] < t3[get<1>(p)]) != get<2>(p)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = true;
        }
    } while (!ans && next_permutation(t3.begin(), t3.end()));
    bool flag = true;
    for (const auto& p : recs) {
        if ((t4[get<0>(p)] < t4[get<1>(p)]) != get<2>(p)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        ans = true;
    }

    cout << (ans ? "Yes" : "No") << '\n';
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
}
