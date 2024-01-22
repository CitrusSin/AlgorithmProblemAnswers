#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << fixed << setprecision(1);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> a0 = a;

    sort(a.begin(), a.end());

    for (int i=0; i<n; i++) {
        int rev = a0[i];
        int idx = lower_bound(a.begin(), a.end(), rev) - a.begin();

        double med;
        if (n % 2) {
            if (idx < n / 2) {
                med = (a[n/2] + a[n/2+1]) / 2.0;
            } else if (idx == n / 2) {
                med = (a[n/2-1] + a[n/2+1]) / 2.0;
            } else {
                med = (a[n/2-1] + a[n/2]) / 2.0;
            }
        } else {
            if (idx < n/2) {
                med = a[n/2];
            } else {
                med = a[n/2-1];
            }
        }

        cout << med << endl;
    }
}