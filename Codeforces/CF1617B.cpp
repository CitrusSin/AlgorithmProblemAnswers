#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a, b, c;
        c = 1;
        if (n % 2 == 0) {
            a = b = n/2;
            b--;
        } else if ((n-1)%4==0) {
            a = (n-1)/2-1;
            b = a+2;
        } else {
            a = (n-1)/2-2;
            b = a+4;
        }

        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}