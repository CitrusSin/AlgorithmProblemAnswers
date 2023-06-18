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
    }

    vector<int> dif(n);
    dif[0] = a[0];
    for (int i=1; i<n; i++) {
        dif[i] = a[i]-a[i-1];
    }

    int negc = 0, posc = 0;
    for (int i=0; i<n; i++) {
        if (dif[i] < 0) negc -= dif[i];
        if (dif[i] > 0) posc += dif[i];
    }

    cout << max(negc, posc) << endl;
    return 0;
}