#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30001;

int dst[N], ds_pos[N], ds_len[N];

int ds_head(int a) {
    if (dst[a] == -1) {
        return a;
    }
    int res = ds_head(dst[a]);
    ds_pos[a] += ds_pos[dst[a]];
    dst[a] = res;
    return res;
}

void ds_merge(int a, int b) {
    int ha = ds_head(a);
    int hb = ds_head(b);
    ds_pos[hb] = ds_len[ha];
    ds_len[ha] += ds_len[hb];
    dst[hb] = ha;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dst, 0xff, sizeof(dst));
    for (int i=0; i<N; i++) ds_len[i] = 1;

    int t;
    cin >> t;
    while (t--) {
        string operand;
        int a, b;
        cin >> operand >> a >> b;
        a--;
        b--;

        if (operand == "M") {
            ds_merge(a, b);
        } else if (operand == "C") {
            int ha = ds_head(a);
            int hb = ds_head(b);
            if (ha != hb) {
                cout << "-1" << endl;
                continue;
            }
            int cnt = abs(ds_pos[a]-ds_pos[b])-1;
            cout << cnt << endl;
        }
    }
    return 0;
}