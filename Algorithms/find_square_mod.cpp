#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t a, m;
    cin >> a >> m;
    for (int64_t i=2; i<m; i++) {
        if ((i*i)%m == a) {
            cout << i << endl;
        }
    }
    return 0;
}