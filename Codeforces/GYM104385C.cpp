#include <bits/stdc++.h>

using namespace std;

int sg(uint64_t r, uint64_t p) {
    if (p%2) return r%2;
    uint64_t val = r%(p+1);
    if (val == p) return 2;
    return val%2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    uint64_t p;
    cin >> n >> p;

    int v = 0;
    while (n--) {
        uint64_t r;
        cin >> r;
        v ^= sg(r, p);
    }

    cout << (v?"GOOD":"BAD") << endl;
    return 0;
}