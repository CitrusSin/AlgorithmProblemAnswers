#include <bits/stdc++.h>

using namespace std;

class BIT {
private:
    vector<int> bit;
    vector<int> value;
    int n;
public:
    BIT(int n) : n(n), bit(n, 0), value(n, 0) {}

    int get(int index) {
        return value[index];
    }

    void add(int index, int val) {
        value[index] += val;
        while (index < n) {
            bit[index] += val;
            index++;
            index += (index & (-index));
            index--;
        }
    }
    
    void set(int index, int val) {
        int diff = val - value[index];
        add(index, diff);
    }

    int sum(int index) {
        int rst = 0;
        while (index >= 0) {
            rst += bit[index];
            index++;
            index -= (index & (-index));
            index--;
        }
        return rst;
    }
};

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

void solve() {
    int n;
    cin >> n;

    vector<int> zeros;
    BIT a(n);
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (p == 0) {
            zeros.push_back(i);
            a.set(i, 1);
        } else {
            a.set(i, p);
        }
    }
    
    for (int i=0; i<n; i++) {
        if (a.sum(i) < 0) {
            cout << -1 << '\n';
            return;
        }
    }

    auto zero_iter = zeros.rbegin();
    deque<int> dec;
    for (int i=n-1; i>=0 && zero_iter != zeros.rend(); i--) {
        while (!dec.empty() && a.sum(dec.back()) >= a.sum(i)) {
            dec.pop_back();
        }
        dec.push_back(i);

        if (i == *zero_iter) {
            int r = a.sum(dec.front());
            if (r >= 2) {
                a.set(i, -1);
            }
            zero_iter++;
        }
    }

    int p=1, q=1;
    for (int i=0; i<n; i++) {
        if (a.get(i) == 1) {
            p++;
            q++;
        } else {
            q--;
        }
    }

    int g = gcd(p, q);
    p /= g;
    q /= g;
    cout << p << ' ' << q << '\n';
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