#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        i64 a, b, n;
        cin >> a >> b >> n;

        a = max(a, b);
        i64 cycle = a+b;
        i64 num = n/2 + (n%2);
        i64 result;
        if (n % 2) {
            result = max(num*cycle, b+(num-1)*cycle);
        } else {
            result = num * cycle + b;
        }
        result -= a;
        cout << result << endl;
    }
    return 0;
}