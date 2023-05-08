#include <bits/stdc++.h>

using namespace std;

void exgcd(int a, int b, int& x, int& y) {
    if (b) {
        exgcd(b, a%b, x, y);
    } else {
        x = 1;
        y = 0;
        return;
    }
    int t = x;
    x = y;
    y = t-(a/b)*y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;
    int a = -y/500, b = y/500;
    while (a < b) {
        a += 3;
        b -= 2;
    }
    if (b < 0 || a > x) {
        cout << -1 << endl;
    } else {
        int p1 = x-a;
        int p2 = a-b;
        int p3 = b;
        if (p2*1000 + p3*2500 == y) {
            cout << p1 << ' ' << p2 << ' ' << p3 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}