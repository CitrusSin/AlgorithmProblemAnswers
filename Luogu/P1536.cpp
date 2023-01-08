#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int dsx[N];

int dshead(int x) {
    if (dsx[x] == -1) {
        return x;
    }
    int res = dshead(dsx[x]);
    dsx[x] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (;;) {
        memset(dsx, 0xff, sizeof(dsx));
        int n, m;
        cin >> n;
        if (n == 0) break;
        cin >> m;
        
        int cnt = n-1;
        while (m--) {
            int a, b;
            cin >> a >> b;
            a = dshead(a-1);
            b = dshead(b-1);
            if (a != b) {
                dsx[b] = a;
                cnt--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}