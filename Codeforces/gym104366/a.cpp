#include <bits/stdc++.h>

using namespace std;

int main() {
    cout << fixed << setprecision(1);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    if (n <= 2) {
        double ans = accumulate(a.begin(), a.end(), 0.0) / a.size();
        cout << ans << '\n';
        return 0;
    }

    double t1 = (double)a.back() - a[1], t2 = (a.back() - a.front()) / 2.0;
    double u1 = min(min(a.front() + t1, a.back() - t1), (double)a[1]);
    double u2 = min(min(a.front() + t2, a.back() - t2), (double)a[1]);

    cout << max(u1, u2) << '\n';
    return 0;
}