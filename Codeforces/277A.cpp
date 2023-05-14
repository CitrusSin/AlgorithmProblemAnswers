#include <bits/stdc++.h>

using namespace std;

class dset {
private:
    vector<int> dt;
public:
    dset(size_t n) : dt(n, -1) {}
    int head(int node) {
        if (dt[node] == -1) return node;
        int tp = head(dt[node]);
        dt[node] = tp;
        return tp;
    }
    bool query(int a, int b) {
        a = head(a), b = head(b);
        return a == b;
    }
    void merge(int a, int b) {
        a = head(a), b = head(b);
        if (a != b) {
            dt[b] = a;
        }
    }
    int count() {
        int cnt = 0;
        for (int p : dt) {
            if (p == -1) cnt++;
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    dset ds(m);
    set<int> langs;
    int zc = 0;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        if (k == 0) {
            zc++;
            continue;
        }
        int last = -1;
        for (int p=0; p<k; p++) {
            int r;
            cin >> r;
            r--;
            langs.insert(r);
            if (last >= 0) {
                ds.merge(last, r);
            }
            last = r;
        }
    }
    set<int> heads;
    for (int l : langs) {
        heads.insert(ds.head(l));
    }
    cout << (max((int)heads.size() -1, 0) + zc) << endl;
    return 0;
}