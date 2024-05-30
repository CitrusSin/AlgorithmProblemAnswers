#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <cstdint>

using namespace std;

vector<pair<int, int>> prime_decompose(int x) {
    vector<pair<int, int>> ans;

    for (int d = 2; d * d < x; d++) {
        int ex = 0;
        while (x % d == 0) {
            x /= d;
            ex++;
        }
        if (ex) {
            ans.emplace_back(d, ex);            
        }
    }
    if (x > 1) ans.emplace_back(x, 1);

    return ans;
}

int ipow(int base, int exp) {
    int ans = 1;
    for (int i=0; i<exp; i++) ans *= base;
    return ans;
}

int main() {
    int x;
    cin >> x;

    vector<pair<int, int>> pdc = prime_decompose(x);

    if (pdc.size() % 2 == 0) {
        cout << 1 << '\n';
        return 0;
    }

    if (pdc.size() == 1) {
        cout << x << '\n';
        return 0;
    }

    for (auto [base, exp] : pdc) {
        if (exp != 1) {
            cout << 1 << '\n';
            return 0;
        }
    }

    int min_val = numeric_limits<int>::max();
    for (auto [base, exp] : pdc) {
        min_val = min(min_val, base);
    }

    cout << min_val << '\n';

    return 0;
}