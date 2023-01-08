#include <bits/stdc++.h>

using namespace std;

int query_ncs(int *arr, int n, int x) {
    int m = arr[x];
    long long min_vals[n+1][n+1];
    int counter = 0;
    for (int i=0; i<=n; i++) min_vals[i][i] = 0x80000000;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            min_vals[i][j] = min(min_vals[i][j-1], (long long)arr[j-1]);
            if (min_vals[i][j] == m) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<m; i++) {
        int opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            arr[x-1] = y;
        } else if (opt == 2) {
            cin >> x;
            cout << query_ncs(arr, n, x-1) << endl;
        }
    }
    return 0;
}