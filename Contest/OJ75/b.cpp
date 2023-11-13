#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    unsigned int mx = 0, mi = 0xffffffff;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        mx |= p;
        mi &= p;
    }

    cout << mx-mi << endl;
    return 0;
}
