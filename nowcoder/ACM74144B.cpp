#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == 'N' && b[i] == 'Y') {
            swap(a[i], b[i]);
        }
        if (a[i] == 'Y') cnt += 2;
        if (b[i] == 'Y') cnt += 1;
    }

    cout << cnt << endl;
    return 0;
}