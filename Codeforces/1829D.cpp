#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b?gcd(b, a%b):a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n < m) {
            cout << "NO" << endl;
            continue;
        }
        int g = gcd(n, m);
        n /= g;
        m /= g;
        int k3=0, k2=0;
        while (n % 3 == 0) {
            n /=3;
            k3++;
        }
        while (m % 2 == 0) {
            m /=2;
            k2++;
        }
        if (n == 1 && m == 1 && k3>=k2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}