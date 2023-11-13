#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int l=0, r=0;
    array<int, 4> arr;
    arr.fill(0);

    int min_len = numeric_limits<int>::max();

    for (; r<n; r++) {
        arr[a[r]-1]++;
        //int num = a[l];
        while (l < r && a[l] == 4 && arr[3] > k) {
            arr[3]--;
            l++;
        }
        while (l < r && a[l] != 4 && arr[a[l]-1] > 1) {
            arr[a[l]-1]--;
            l++;
        }
        if (arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1 && arr[3] >= k) {
            min_len = min(min_len, r-l+1);
        }
    }

    cout << min_len << endl;
    return 0;
}