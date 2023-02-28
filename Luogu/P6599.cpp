#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
using u64 = unsigned long long;

vector<u64> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        u64 n, l;
        cin >> n >> l;
        if (n == 1) {
            cout << 0 << endl;
        } else {
            u64 s = arr.size();
            while (s < l) {
                arr.push_back((s+1)/2);
                if (s > 0) arr[s] += arr[s-1];
                s++;
            }
            int digit = 0;
            while (n > 0) {
                n >>= 1;
                digit++;
            }
            u64 result = (1 << digit)-1;
            result %= mod;
            result *= arr[l-1];
            result %= mod;
            cout << result << endl;
        }
    }
    return 0;
}