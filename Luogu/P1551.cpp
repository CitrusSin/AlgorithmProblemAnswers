#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int dsx[N];

int dshead(int x) {
    if (dsx[x] == -1) {
        return x;
    }
    int res = dshead(dsx[x]);
    dsx[x] = res;
    return res;
}

void dsmerge(int a, int b) {
    a = dshead(a);
    b = dshead(b);
    if (a != b) {
        dsx[b] = a;
    }
}

bool dsquery(int a, int b) {
    a = dshead(a);
    b = dshead(b);
    return a == b;
}

int main() {
    memset(dsx, 0xff, sizeof(dsx));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    while (m--) {
        int i, j;
        cin >> i >> j;
        dsmerge(--i, --j);
    }
    while (p--) {
        int i, j;
        cin >> i >> j;
        cout << (dsquery(--i, --j)?"Yes":"No") << endl;
    }
    return 0;
}