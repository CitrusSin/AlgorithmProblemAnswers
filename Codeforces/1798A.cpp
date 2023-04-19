#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& a, vector<int>& b) {
    int n = a.size();
    for (int i=0; i<n-1; i++) {
        if (a[i] > a[n-1]) {
            swap(a[i], b[i]);
            if (a[i] > a[n-1] || b[i] > b[n-1]) {
                return false;
            }
        } else if (b[i] > b[n-1]) {
            swap(a[i], b[i]);
            if (a[i] > a[n-1] || b[i] > b[n-1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }
        cout << (solve(a, b)?"Yes":"No") << endl;
    }
    return 0;
}