#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

const int p1 = 991, p2 = 100000007;

int atoi_mod(const string& s, int p) {
    auto it = s.begin();
    bool neg = false;
    if (*it == '-') {
        neg = true;
        it++;
    }
    int64_t res = 0;
    for (; it != s.end(); it++) {
        res *= 10;
        res %= p;
        res += (*it)-'0';
        res %= p;
    }
    return neg?(p-res):res;
}

int calculate_polynomial_mod(const vector<int>& coefficients, int x, int p) {
    int64_t res = 0;
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); it++) {
        res *= x;
        res %= p;
        res += *it;
        res %= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    array<vector<int>, 2> a = {vector<int>(n+1), vector<int>(n+1)};
    for (int i=0; i<=n; i++) {
        string rs;
        cin >> rs;
        a[0][i] = atoi_mod(rs, p1);
        a[1][i] = atoi_mod(rs, p2);
    }

    vector<int> solves;
    for (int i=1; i<=p1; i++) {
        if (calculate_polynomial_mod(a[0], i%p1, p1) == 0) {
            for (int j=i; j<=m; j+=p1) {
                if (calculate_polynomial_mod(a[1], j%p2, p2) == 0) {
                    solves.push_back(j);
                }
            }
        }
    }

    sort(solves.begin(), solves.end());
    cout << solves.size() << endl;
    for (int s : solves) cout << s << endl;
    return 0;
}