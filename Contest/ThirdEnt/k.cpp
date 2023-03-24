#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

list<int> factors_set(int x) {
    list<int> s;
    insert_iterator<list<int>> isit = inserter(s, s.begin());
    int upper = (int)sqrt(x);
    for (int i=1; i<=upper; i++) {
        if (x % i == 0) {
            int j = x/i;
            *isit = i;
            if (i != j) *isit = j;
        }
    }
    s.sort();
    return s;
}

bool is_prime(int x) {
    int upper = (int)sqrt(x);
    for (int i=2; i<=upper; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    list<int> factors = factors_set(n);
    u64 factor_sum = 0;
    for (auto it = factors.begin(); it != factors.end(); it++) {
        int f = *it;
        if (f != 1) {
            for (auto it2 = it; it2!=factors.end();) {
                if (it2 != it && (*it2) % f == 0) {
                    it2 = factors.erase(it2);
                } else {
                    it2++;
                }
            }

            if (is_prime(f)) factor_sum += f;
        }
    }

    cout << factor_sum << endl;
    return 0;
}