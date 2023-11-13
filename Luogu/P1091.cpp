#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> member(n);
    for (int i=0; i<n; i++) {
        cin >> member[i];
    }

    vector<int> a(n), b(n);

    for (int i=0; i<n; i++) {
        int max_len = 0;
        for (int j=0; j<i; j++) {
            if (member[i] > member[j] && a[j] > max_len) {
                max_len = a[j];
            }
        }
        a[i] = max_len+1;
    }

    for (int i=n-1; i>=0; i--) {
        int max_len = 0;
        for (int j=i+1; j<n; j++) {
            if (member[i] > member[j] && b[j] > max_len) {
                max_len = b[j];
            }
        }
        b[i] = max_len+1;
    }

    int max_len = 0;
    for (int i=0; i<n; i++) {
        int len = a[i] + b[i] - 1;
        if (len > max_len) max_len = len;
    }

    cout << n-max_len << endl;
    return 0;
}