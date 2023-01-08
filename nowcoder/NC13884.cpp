#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const int mod = 1e9+7;

ull combine(int m, int n) {
    if (n > m/2) {
        return combine(m, m-n);
    }
    
    int i=m, j=1;
    ull result = 1;
    for (int t=0; t<n; t++) {
        result *= i;
        result /= j;
        i--;
        j++;
    }
    return result;
}

int fast_pow(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base % mod;
    
    int b2 = fast_pow(base, exp/2);
    if (exp % 2 == 1) {
        return (b2*b2%mod)*base%mod;
    } else {
        return b2*b2%mod;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int r=0; r<t; r++) {
        int n, m, k;
        cin >> n >> m >> k;

        if (k == 1) {
            if (n == 1) {
                cout << m << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }
        
        if (n<=2) {
            ull result = (k*fast_pow(k-1, n-1) - (k-1)*fast_pow(k-2, n-1))%mod;
            result *= combine(m, k)%mod;
            cout << result << endl;
        } else {
            ull result = 0;
            for (int i=0; i<n-1; i++) {
                result += fast_pow(k-1, i) * fast_pow(k-2, n-2-i) % mod;
                result %= mod;
            }
            result *= k;
            result %= mod;
            result += fast_pow(k-2, n-1);
            result %= mod;
            result *= combine(m, k)%mod;
            result %= mod;
            cout << result << endl;
        }
        
    }
    return 0;
}