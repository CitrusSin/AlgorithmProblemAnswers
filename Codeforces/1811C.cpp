#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n-1);
        for (int i=0; i<n-1; i++) cin >> arr[i];
        vector<int> arr2(n);
        arr2[0] = arr[0];
        for (int i=1; i<n-1; i++) {
            arr2[i] = min(arr[i-1], arr[i]);
        }
        arr2[n-1] = arr[n-2];
        for (int p : arr2) {
            cout << p << ' ';
        }
        cout << endl;
    }
    return 0;
}