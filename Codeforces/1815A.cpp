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
        vector<int64_t> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        for (int i=1; i<n-1; i++) {
            if (arr[i-1] > arr[i]) {
                int64_t inc = arr[i-1]-arr[i];
                arr[i] += inc;
                arr[i+1] += inc;
            }
        }
        bool result = arr[n-1] >= arr[n-2];
        cout << (result?"YES":"NO") << endl;
    }
    return 0; 
}