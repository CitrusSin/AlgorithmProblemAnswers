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
        i64 max;
        i64 lazy;
        i64 lb, rb;
    };
    vector<segnode> tr;
    u64 sz;

    void init(u64 node, i64 l, i64 r) {
        //tr[node].sum = 0;
        tr[node].max = 0;
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
        //tr[node].sum += delta * (tr[node].rb - tr[node].lb + 1);
        tr[node].max += delta;
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
        tr[node].max = max(tr[node * 2 + 1].max, tr[node * 2 + 2].max);
    }

    i64 querymax(u64 node, u64 l, u64 r) {
        if (l <= tr[node].lb && r >= tr[node].rb) {
            return tr[node].max;
        }

        pushdown(node);
        i64 mid = tr[node].lb + (tr[node].rb - tr[node].lb) / 2;
        i64 ans = numeric_limits<i64>::min();
        if (l <= mid) {
            ans = max(ans, querymax(node * 2 + 1, l, r));
        }
        if (r > mid) {
            ans = max(ans, querymax(node * 2 + 2, l, r));
        }
        return ans;
    }
public:
    explicit segtree(u64 size) : tr(4*size), sz(size) {
        init(0, 0, size-1);
    }

    void set(u64 idx, i64 value) {
        i64 prev = querymax(0, idx, idx);
        modify(0, idx, idx, value - prev);
    }

    i64 range_max(u64 l, u64 r) {
        return querymax(0, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, d;
    cin >> n >> d;

    vector<i64> a(n);
    for (i64 i=0; i<n; i++) cin >> a[i];

    i64 maxv = *max_element(a.begin(), a.end());

    segtree sgt(maxv+1);
    for (i64 i=0; i<n; i++) {
        i64 down = a[i] - d, up = a[i] + d;
        down = max<i64>(0, down);
        up = min<i64>(maxv, up);

        i64 max_count = sgt.range_max(down, up);
        sgt.set(a[i], max_count+1);
    }

    i64 ans = sgt.range_max(0, maxv);
    cout << ans << endl;
    return 0;
}