#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int arr[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    i64 sums[n][n];
    sums[0][0] = arr[0][0];
    for (int i=1; i<n; i++) {
        sums[i][0] = sums[i-1][0] + arr[i][0];
        sums[0][i] = sums[0][i-1] + arr[0][i];
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            sums[i][j] = arr[i][j]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
        }
    }
    
    i64 max_sum = 0;
    for (int i0=0; i0<n; i0++) {
        for (int j0=0; j0<n; j0++) {
            for (int i1=i0; i1<n; i1++) {
                for (int j1=j0; j1<n; j1++) {
                    i64 s = sums[i1][j1];
                    if (i0 > 0) s -= sums[i0-1][j1];
                    if (j0 > 0) s -= sums[i1][j0-1];
                    if (i0 > 0 && j0 > 0) s += sums[i0-1][j0-1];
                    if (s > max_sum) max_sum = s;
                }
            }
        }
    }
    
    cout << max_sum << endl;
    return 0;
}