#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

int main() {
    i64 n, k;
    cin >> n >> k;
    
    i128 i1 = i128(n)*(k-1);
    if (i1%k == 0) {
        cout << i64(i1/k) << endl;
    } else {
        cout << i64(i1/k+1) << endl;
    }
    return 0;
}