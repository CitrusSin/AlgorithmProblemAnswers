#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 solve(u64 x) {
    if (x == 0) return 0;
    if (x == 1) return 1;

    u64 layer = floor(0.5*(sqrt(1+8*(double)x)-1));
    if (layer*(layer+1)/2 != x) layer++;
    u64 ltop = layer*(layer-1)/2;
    u64 st = x-ltop;
    u64 rem = layer-st;

    u64 r = st==1?0:solve(x-layer);
    for (int p=0; p<=rem; p++) {
        r += x*x;
        x -= layer-p-1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}