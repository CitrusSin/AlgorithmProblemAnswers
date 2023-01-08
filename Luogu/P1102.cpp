#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    long long counter = 0;
    int i=0, j=0;
    while (i < n && j < n) {
        int r = arr[i]-arr[j];
        if (r < c) {
            i++;
        } else if (r > c) {
            j++;
        } else {
            long long iinc = 0, jinc = 0;
            int prevarri = arr[i], prevarrj = arr[j];
            while (arr[i] == prevarri) {
                i++;
                iinc++;
            }
            while (arr[j] == prevarrj) {
                j++;
                jinc++;
            }
            counter += iinc * jinc;
        }
    }

    cout << counter << endl;
    return 0;
}