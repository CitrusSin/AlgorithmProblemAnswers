#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class seg_tree {
public:
    seg_tree(size_t n) : tree(4*n), minv(4*n), lazy(4*n), len(n) {
        init(0, 0, n-1);
    }

    void add(size_t l, size_t r, const int64_t& value) {
        modify(0, 0, len-1, l, r, value);
    }

    int64_t range_sum(size_t l, size_t r) {
        return query_sum(0, 0, len-1, l, r);
    }
private:
    std::vector<int64_t> tree, minv, lazy;
    size_t len;

    void init(size_t idx, size_t l, size_t r) {
        tree[idx] = 0;
        minv[idx] = 0;
        lazy[idx] = 0;

        if (l < r) {
            size_t mid = l + (r - l) / 2;
            init(idx*2+1, l, mid);
            init(idx*2+2, mid+1, r);
        }
    }

    void pushup(size_t idx, size_t nl, size_t nr, int64_t delta) {
        tree[idx] += delta * (nr - nl + 1);
        minv[idx] += delta;
        lazy[idx] += delta;
    }

    void pushdown(size_t idx, size_t nl, size_t nr) {
        if (nr > nl) {
            size_t mid = nl + (nr - nl) / 2;
            pushup(idx*2+1, nl, mid, lazy[idx]);
            pushup(idx*2+2, mid+1, nr, lazy[idx]);
        }
        lazy[idx] = 0;
    }

    void modify(size_t idx, size_t nl, size_t nr, size_t l, size_t r, int64_t delta) {
        if (l <= nl && nr <= r) {
            if (minv[idx] + delta < 0) delta = -minv[idx];
            pushup(idx, nl, nr, delta);
            return;
        }

        pushdown(idx, nl, nr);

        size_t mid = nl + (nr - nl) / 2;
        if (l <= mid) {
            modify(idx*2+1, nl, mid, l, r, delta);
        }
        if (r > mid) {
            modify(idx*2+2, mid+1, nr, l, r, delta);
        }

        tree[idx] = tree[idx*2+1] + tree[idx*2+2];
        minv[idx] = std::min(minv[idx*2+1], minv[idx*2+2]);
    }

    int64_t query_sum(size_t idx, size_t nl, size_t nr, size_t l, size_t r) {
        if (l <= nl && nr <= r) {
            return tree[idx];
        }

        pushdown(idx, nl, nr);

        size_t mid = nl + (nr - nl) / 2;
        int64_t ans = 0;
        if (l <= mid) {
            ans += query_sum(idx*2+1, nl, mid, l, r);
        }
        if (r > mid) {
            ans += query_sum(idx*2+2, mid+1, nr, l, r);
        }

        return ans;
    }

    int64_t query_min(size_t idx, size_t nl, size_t nr, size_t l, size_t r) {
        if (l <= nl && nr <= r) {
            return minv[idx];
        }

        pushdown(idx, nl, nr);

        size_t mid = nl + (nr - nl) / 2;
        int64_t ans = std::numeric_limits<int64_t>::max();
        if (l <= mid) {
            ans = std::min(ans, query_min(idx*2+1, nl, mid, l, r));
        }
        if (r > mid) {
            ans = std::min(ans, query_min(idx*2+2, mid+1, nr, l, r));
        }

        return ans;
    }
};


int main() {
    int h, w, m;
    cin >> h >> w >> m;

    while (m--) {
        int t, a, x;
        cin >> t >> a >> x;
    }
}