#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;
using i64 = int64_t;

//const int N = 10001;
//u64 squares[N];

vector<pair<i64, i64>> square_split(u64 x) {
    //u64 index = upper_bound(squares, squares+N, x) - squares;
    u64 idx = sqrt(x)+3;
    u64 i = 0, j = idx;
    vector<pair<i64, i64>> result;
    while (i <= j) {
        u64 val = j*j+i*i;
        if (val == x) {
            result.emplace_back(i, j);
            if (i != j) result.emplace_back(j, i);
            result.emplace_back(-i64(i), j);
            if (i != j) result.emplace_back(-i64(j), i);
            result.emplace_back(i, -i64(j));
            if (i != j) result.emplace_back(j, -i64(i));
            result.emplace_back(-i64(i), -i64(j));
            if (i != j) result.emplace_back(-i64(j), -i64(i));
            j--;
        } else if (val > x) {
            j--;
        } else {
            i++;
        }
    }
    return result;
}

constexpr i64 squ(i64 x) {
    return x*x;
}

i64 gcd(i64 a, i64 b) {
    return b?gcd(b, a%b):a;
}

constexpr pair<i64, i64> operator-(const pair<i64, i64>& p1, const pair<i64, i64>& p2) {
    return make_pair(p1.first - p2.first, p1.second - p2.second);
}

void solve() {
    i64 x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    i64 l1 = squ(x2-x1)+squ(y2-y1);
    i64 l2 = squ(x3-x1)+squ(y3-y1);
    i64 l3 = squ(x3-x2)+squ(y3-y2);
    i64 k = gcd(l1, gcd(l2, l3));
    l1 /= k;
    l2 /= k;
    l3 /= k;

    auto p1 = square_split(l1), p2 = square_split(l2);
    for (const auto& pt1 : p1) {
        for (const auto& pt2 : p2) {
            auto v3 = pt1-pt2;
            if (squ(v3.first) + squ(v3.second) == l3) {
                cout << "0 0 " << pt1.first << ' ' << pt1.second << ' ' << pt2.first << ' ' << pt2.second << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    /*
    for (u64 i=0; i<N; i++) {
        squares[i] = i*i;
    }
    */

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}