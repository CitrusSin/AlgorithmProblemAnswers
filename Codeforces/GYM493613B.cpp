#include <iostream>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<i64> a(n);

    for (size_t i=0; i<n; i++) cin >> a[i];

    i64 num = 0;
    bool num1shifted = false;
    for (size_t i=0; i<n; i++) {
        if (num % 2) num1shifted = true;
        bool ct = num < 0 && num % 2;
        num /= 2;
        if (ct) num--;
        num += a[i];
        if (!num1shifted && num == 0) {
            cout << '0';
        } else if (num >= 0) {
            cout << '+';
        } else {
            cout << '-';
        }
    }
    cout << endl;

    return 0;
}