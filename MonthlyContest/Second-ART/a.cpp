#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 n, k;
    cin >> n >> k;
    
    i64 lower = 1;
    i64 upper = n;
    while (upper > lower) {
        i64 mid = (upper + lower) / 2;
        i64 sum = mid;
        i64 p = k;
        for (;;) {
            i64 term = mid/p;
            p*=k;
            if (term == 0) break;
            sum += term;
            if (sum >= n) break;
        }
        if (sum >= n) {
            upper = mid;
        } else {
            lower = mid+1;
        }
    }
    cout << upper << endl;
    return 0;
}