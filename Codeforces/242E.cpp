#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

class SegTree {
private:
    struct Node {
        i64 sum;
        size_t l, r;
        bool lazy_tag;
    };
    vector<Node> sd;

    void init(size_t i, size_t l, size_t r) {
        sd[i].l = l;
        sd[i].r = r;
        sd[i].sum = 0;
        sd[i].lazy_tag = false;

        if (l != r) {
            size_t mid = l + (r - l) / 2;
            init(i*2+1, l, mid);
            init(i*2+2, mid+1, r);
        }
    }

    void push_up(i64 i) {
        sd[i].sum = (sd[i].r - sd[i].l + 1) - sd[i].sum;
        sd[i].lazy_tag = !sd[i].lazy_tag;
    }

    void push_down(i64 i) {
        if (!sd[i].lazy_tag) {
            return;
        }

        sd[i].lazy_tag = false;
        if (sd[i].l != sd[i].r) {
            push_up(i*2+1);
            push_up(i*2+2);
        }
    }

    void flip_range(size_t i, size_t l, size_t r) {
        if (l <= sd[i].l && sd[i].r <= r) {
            push_up(i);
            return;
        }

        push_down(i);

        size_t mid = sd[i].l + (sd[i].r - sd[i].l) / 2;
        if (l <= mid) {
            flip_range(i*2+1, l, r);
        }
        if (r > mid) {
            flip_range(i*2+2, l, r);
        }
        sd[i].sum = sd[i*2+1].sum + sd[i*2+2].sum;
    }

    i64 query_sum(size_t i, size_t l, size_t r) {
        if (l <= sd[i].l && sd[i].r <= r) {
            return sd[i].sum;
        }

        push_down(i);

        size_t mid = sd[i].l + (sd[i].r - sd[i].l) / 2;
        i64 ans = 0;
        if (l <= mid) {
            ans += query_sum(i*2+1, l, r);
        }
        if (r > mid) {
            ans += query_sum(i*2+2, l, r);
        }
        return ans;
    }
public:
    SegTree(size_t l, size_t r) : sd((r - l + 1) * 4) {
        init(0, l, r);
    }

    void flip_range(size_t l, size_t r) {
        flip_range(0, l, r);
    }

    i64 query_sum(size_t l, size_t r) {
        return query_sum(0, l, r);
    }

    void set_bit(size_t i, bool value) {
        if (bool(query_sum(i, i)) ^ value) {
            flip_range(i, i);
        } 
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<SegTree> segts;
    const int bits = 24;
    segts.reserve(bits);
    for (int i=0; i<bits; i++) segts.emplace_back(0, n-1);

    for (int i=0; i<n; i++) {
        for (int b=0; b<bits; b++) {
            segts[b].set_bit(i, (a[i] >> b) & 1);
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            size_t l, r;
            cin >> l >> r;
            l--;
            r--;
            i64 ans = 0;
            for (int b=0; b<bits; b++) {
                ans += segts[b].query_sum(l, r) << b;
            }
            cout << ans << '\n';
        } else if (t == 2) {
            size_t l, r;
            int x;
            cin >> l >> r >> x;
            l--;
            r--;
            for (int b=0; b<bits; b++) {
                if (!((x >> b) & 1)) continue;
                segts[b].flip_range(l, r);
            }
        }
    }
    return 0;
}