#include <iostream>
#include <vector>
#include <cinttypes>
#include <algorithm>
#include <limits>

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

class segtree {
private:
    struct segnode {
        i64 sum;
        i64 lazy;
        i64 lb, rb;
    };
    vector<segnode> tr;

    void init(u64 node, i64 l, i64 r) {
        tr[node].sum = 0;
        tr[node].lazy = 0;
        tr[node].lb = l;
        tr[node].rb = r;

        if (l != r) {
            i64 mid = l + (r-l)/2;
            init(node * 2 + 1, l, mid);
            init(node * 2 + 2, mid+1, r);
        }
    }

    void pushup(u64 node, i64 delta) {
        tr[node].lazy += delta;
        tr[node].sum += delta * (tr[node].rb - tr[node].lb + 1);
    }

    void pushdown(u64 node) {
        if (tr[node].lb == tr[node].rb || tr[node].lazy == 0) return;
        pushup(node * 2 + 1, tr[node].lazy);
        pushup(node * 2 + 2, tr[node].lazy);
        tr[node].lazy = 0;
    }

    void modify(u64 node, u64 l, u64 r, u64 delta) {
        if (l <= tr[node].lb && r >= tr[node].rb) {
            pushup(node, delta);
            return;
        }

        pushdown(node);
        i64 mid = tr[node].lb + (tr[node].rb - tr[node].lb) / 2;
        if (l <= mid) {
            modify(node * 2 + 1, l, r, delta);
        }
        if (r > mid) {
            modify(node * 2 + 2, l, r, delta);
        }
        tr[node].sum = tr[node * 2 + 1].sum + tr[node * 2 + 2].sum;
    }

    i64 querysum(u64 node, u64 l, u64 r) {
        if (l <= tr[node].lb && r >= tr[node].rb) {
            return tr[node].sum;
        }

        pushdown(node);
        i64 mid = tr[node].lb + (tr[node].rb - tr[node].lb) / 2;
        i64 ans = 0;
        if (l <= mid) {
            ans += querysum(node * 2 + 1, l, r);
        }
        if (r > mid) {
            ans += querysum(node * 2 + 2, l, r);
        }
        return ans;
    }
public:
    explicit segtree(u64 size) : tr(4*size) {
        init(0, 0, size-1);
    }

    void set(u64 idx, i64 value) {
        i64 prev = querysum(0, idx, idx);
        modify(0, idx, idx, value - prev);
    }

    i64 range_sum(u64 l, u64 r) {
        return querysum(0, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        segtree sgt(n);
        for (int i=0; i<n; i++) {
            i64 p;
            cin >> p;
            sgt.set(i, p);
        }
        
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x;
                i64 y;
                cin >> x >> y;
                x--;
                sgt.set(x, y);
            } else if (op == 2) {
                i64 l, r;
                cin >> l >> r;
                l--, r--;
                i64 p1 = sgt.range_sum(l, r-1) - sgt.range_sum(r, r);
                i64 p2 = sgt.range_sum(l, l) - sgt.range_sum(l+1, r);
                i64 ans = max(p1, p2);
                cout << p1 << '\n';
            }
        }
    }
    return 0;
}