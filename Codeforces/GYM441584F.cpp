#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int total = 0;
    for (int i=0, j=0; i<n; i++) {
        int rem = a[i];
        while (j < m && b[j] <= rem) {
            rem -= b[j++];
            total++;
        }
    }
    cout << total << endl;
    return 0;
}