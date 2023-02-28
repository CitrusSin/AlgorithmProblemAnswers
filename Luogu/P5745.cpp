#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int max_sum = 0, max_i = 0, max_j = 0;
    int i=0, j=1, sum=arr[0];
    while (i < n && j < n) {
        if (sum<=m) {
            if (sum > max_sum) {
                max_sum = sum;
                max_i = i;
                max_j = j-1;
            }
        }
        if (sum < m) {
            sum += arr[j++];
        } else {
            sum -= arr[i++];
        }
    }
    if (sum<=m) {
        if (sum > max_sum) {
            max_sum = sum;
            max_i = i;
            max_j = j-1;
        }
    }
    cout << max_i+1 << " " << max_j+1 << " " << max_sum << endl;
    return 0;
}