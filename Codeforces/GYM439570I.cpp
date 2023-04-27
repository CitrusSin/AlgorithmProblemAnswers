#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> males(n), females(m);
    for (int i=0; i<n; i++) cin >> males[i];
    for (int i=0; i<m; i++) cin >> females[i];

    sort(males.begin(), males.end());
    sort(females.begin(), females.end());

    int l, r;
    cin >> l >> r;

    uint64_t total = 0;

    for (int i=0; i<n; i++) {
        int p1 = males[i];

        if (p1 != 0) {
            int upper = r / p1;
            int lower = l / p1;
            while (lower*p1>l) {
                if (p1 > 0) {
                    lower--;
                } else {
                    lower++;
                }
            }
            while (lower*p1<l) {
                if (p1 > 0) {
                    lower++;
                } else {
                    lower--;
                }
            }
            while (upper*p1<r) {
                if (p1 > 0) {
                    upper++;
                } else {
                    upper--;
                }
            }
            while (upper*p1>r) {
                if (p1 > 0) {
                    upper--;
                } else {
                    upper++;
                }
            }
            if (upper < lower) swap(upper, lower);

            auto up = upper_bound(females.begin(), females.end(), upper);
            auto down = lower_bound(females.begin(), females.end(), lower);
            int s = up-down;

            total += s;
        } else {
            if (0 >= l && 0 <= r) {
                total += females.size();
            }
        }
    }

    cout << total << endl;
    return 0;
}