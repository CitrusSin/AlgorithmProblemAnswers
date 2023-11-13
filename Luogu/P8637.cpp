#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }

    int count = 0;
    for (int i=0; i<n; i++) {
        while (a[i] != i) {
            int sw = a[a[i]];
            a[a[i]] = a[i];
            a[i] = sw;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}