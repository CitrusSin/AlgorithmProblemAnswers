#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<u64> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    u64 sum = 0, sumsq = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
        sumsq += arr[i]*arr[i];
    }
    
    u64 result = (sum*sum - sumsq)/2;
    cout << result << endl;
    return 0;
}