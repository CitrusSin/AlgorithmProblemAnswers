#include <iostream>
#include <vector>

using namespace std;
using i64 = int64_t;

int main() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n-1; i++) {
        i64 s, t;
        cin >> s >> t;
        i64 unit = a[i] / s;
        a[i] -= unit * s;
        a[i+1] += unit * t;
    }

    cout << a[n-1] << '\n';
}