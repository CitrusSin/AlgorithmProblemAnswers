#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int djs[N];

int djs_head(int x) {
    if (djs[x] == 0) return x;
    int res = djs_head(djs[x]);
    djs[x] = res;
    return res;
}

void djs_merge(int a, int b) {
    a = djs_head(a);
    b = djs_head(b);
    if (a != b) {
        djs[b] = a;
    }
}

bool djs_query(int a, int b) {
    return djs_head(a) == djs_head(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    for (int i=0; i<q; i++) {
        int c, u, v;
        cin >> c >> u >> v;
        u++;
        v++;
        if (c) {
            cout << (djs_query(u, v)?1:0) << endl;
        } else {
            djs_merge(u, v);
        }
    }
    return 0;
}