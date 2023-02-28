#include <bits/stdc++.h>
using namespace std;

// Disjoint set implementation
// Only support continuous non-negative integers start from 0
class dset_raw {
public:
    void init(int n);
    void expand(int new_size);
    size_t size() const;

    int head(int x) const;
    void merge(int a, int b);
    bool query(int a, int b) const;

    int count_set() const;
private:
    mutable vector<int> dst;
};

void dset_raw::init(int n) {
    dst.assign(n, -1);
}

void dset_raw::expand(int new_size) {
    dst.resize(new_size, -1);
}

size_t dset_raw::size() const {
    return dst.size();
}

int dset_raw::head(int x) const {
    if (dst[x] == -1) {
        return x;
    } else {
        int res = head(dst[x]);
        dst[x] = res;
        return res;
    }
}

void dset_raw::merge(int a, int b) {
    int max_n = max(a, b);
    if (max_n > size()) {
        expand(max_n+1);
    }
    a = head(a);
    b = head(b);
    if (a != b) dst[b] = a;
}

bool dset_raw::query(int a, int b) const {
    return head(a) == head(b);
}

int dset_raw::count_set() const {
    int cnt = 0;
    for (int p : dst) {
        if (p == -1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int case_cnt = 1;
    while (cin >> n >> m, n != 0 || m != 0) {
        dset_raw s;
        s.init(n);
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            s.merge(a-1, b-1);
        }
        cout << "Case " << case_cnt++ << ": " << s.count_set() << endl;
    }
    return 0;
}