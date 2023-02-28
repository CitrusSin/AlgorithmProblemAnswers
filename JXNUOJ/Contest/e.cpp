#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        int sw = a;
        a = b;
        b = sw;
    }
    while (b != 0) {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m) << endl;
    return 0;
}