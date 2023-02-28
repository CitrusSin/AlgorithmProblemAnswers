#include <bits/stdc++.h>

using namespace std;

bool check(long long n) {
    if (n % 2 == 0) {
        while (n%2==0) {
            n /= 2;
        }
        if (n!=1) {
            return true;
        }
        return false;
    } else {
        if (n <= 3) {
            return false;
        }
        long long upper = (long long)sqrt(n);
        for (long long factor=3; factor<=upper; factor+=2) {
            if (n % factor == 0) {
                return true;
            }
        }
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        long long n;
        cin >> n;

        cout << (check(n)?"YES":"NO") << endl;
    }
    return 0;
}