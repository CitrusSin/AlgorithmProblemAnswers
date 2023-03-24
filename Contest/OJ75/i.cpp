#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    k = abs(k);

    if (k == 0) {
        u64 total_cnt = 0;
        u64 cnt = 1;
        for (int i=1; i<n; i++) {
            if (arr[i] == arr[i-1]) {
                cnt++;
            } else {
                total_cnt += cnt*(cnt-1)/2;
                cnt = 1;
            }
        }
        total_cnt += cnt*(cnt-1)/2;
        cout << total_cnt << endl;
    } else {
        int p=0, q=0;
        u64 total_cnt = 0;
        while (p < n && q < n) {
            int diff = arr[q] - arr[p];
            if (diff < k) {
                q++;
            } else if (diff > k) {
                p++;
            } else {
                u64 cntl=1, cntr=1;
                while (++p < n && arr[p] == arr[p-1]) {
                    cntl++;
                }
                while (++q < n && arr[q] == arr[q-1]) {
                    cntr++;
                }
                total_cnt += cntl * cntr;
            }
        }
        cout << total_cnt << endl;
    }
    return 0;
}