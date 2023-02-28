#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ull n;
    while (cin >> n) {
        ull count = 3*(1<<(n-1))-2;
        cout << count << endl;
    }
    return 0;
}