#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cnt = 0, bound = n/2;
    if (n % 2) bound++;
    for (int i=1; i<n; i++) {
        int rem = (i*i)%n;
        if (rem < bound) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
