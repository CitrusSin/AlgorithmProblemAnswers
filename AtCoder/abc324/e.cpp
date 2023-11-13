#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cinttypes>

using i64 = int64_t;
using u64 = uint64_t;

class SegTree {
private:
    struct Node {
        i64 l, r;
        i64 sum, lazy;
    };

    std::vector<Node> seg;

    void build(size_t i, i64 l, i64 r) {
        seg[i].l = l;
        seg[i].r = r;
        seg[i].sum = 0;
        seg[i].lazy = 0;

        if (l != r) {
            i64 mid = l + (r - l) / 2;
            build(2*i+1, l, mid);
            build(2*i+2, mid+1, r);
        }
    }

    void pushUp(size_t i, i64 val) {
        seg[i].sum += (seg[i].r - seg[i].l + 1) * val;
        seg[i].lazy += val;
    }

    void pushDown(size_t i) {
        if (seg[i].l == seg[i].r) {
            seg[i].lazy = 0;
            return;
        }
        if (seg[i].lazy) {
            pushUp(2*i+1, seg[i].lazy);
            pushUp(2*i+2, seg[i].lazy);
        }
        seg[i].lazy = 0;
    }

    void modify(size_t i, i64 l, i64 r, i64 delta) {
        if (seg[i].l >= l && seg[i].r <= r) {
            pushUp(i, delta);
            return;
        }
        pushDown(i);
        i64 mid = seg[i].l + (seg[i].r-seg[i].l)/2;
        if (l <= mid) {
            modify(2*i+1, l, r, delta);
        }
        if (r > mid) {
            modify(2*i+2, l, r, delta);
        }
        seg[i].sum = seg[2*i+1].sum + seg[2*i+2].sum;
    }

    i64 ask(size_t i, i64 l, i64 r) {
        if (seg[i].l >= l && seg[i].r <= r) {
            return seg[i].sum;
        }
        pushDown(i);
        i64 ans = 0;
        i64 mid = seg[i].l + (seg[i].r-seg[i].l)/2;
        if (l <= mid) {
            ans += ask(2*i+1, l, r);
        }
        if (r > mid) {
            ans += ask(2*i+2, l, r);
        }
        return ans;
    }

public:
    SegTree(i64 n) : seg(4 * n) {
        build(0, 0, n-1);
    }

    void add(i64 l, i64 r, i64 delta) {
        modify(0, l, r, delta);
    }

    i64 query(i64 l, i64 r) {
        return ask(0, l, r);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::string t;
    std::cin >> n >> t;

    std::vector<u64> sf(n), pf(n);

    for (int r=0; r<n; r++) {
        std::string s;
        std::cin >> s;

        u64 pflen = 0;
        for (size_t i=0; i<s.size() && pflen < t.size(); i++) {
            if (s[i] == t[pflen]) pflen++;
        }

        u64 sflen = 0;
        for (size_t i=0; i<s.size() && sflen < t.size(); i++) {
            if (s[s.size()-i-1] == t[t.size()-sflen-1]) sflen++;
        }

        sf[r] = sflen;
        pf[r] = pflen;
    }

    //count pf[i] + sf[j] >= t.size();
    // pf[i] >= t.size() - sf[j];
    u64 ans = 0;
    SegTree sgtpf(t.size()+1);
    for (u64 v : pf) {
        sgtpf.add(v, v, 1);
    }
    for (int j=0; j<n; j++) {
        if (t.size() <= sf[j]) {
            ans += n;
            continue;
        }
        i64 l = t.size() - sf[j];
        ans += sgtpf.query(l, t.size());
    }

    std::cout << ans << std::endl;
    return 0;
}