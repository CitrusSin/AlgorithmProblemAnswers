#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int pos = 0, cnt = 0;
    while (pos < n-1) {
        pos += a[pos];
        cnt++;
    }
    cout << (pos == n-1 ? "Yes" : "No") << endl << cnt << endl;
}