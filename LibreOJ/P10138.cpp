#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

class SegTree {
private:
    struct SegNode {
        i64 l, r;
        i64 sum, max;
        i64 lazy;
    };

    mutable vector<SegNode> sgt;

    void build(size_t i, i64 l, i64 r, const function<i64()>& pro) {
        sgt[i].l = l;
        sgt[i].r = r;

        sgt[i].lazy = 0;

        if (l == r) {
            sgt[i].sum = sgt[i].max = pro();
        } else {
            i64 mid = l + (r - l) / 2;
            build(2*i+1, l, mid, pro);
            build(2*i+2, mid+1, r, pro);

            sgt[i].sum = sgt[2*i+1].sum + sgt[2*i+2].sum;
            sgt[i].max = max(sgt[2*i+1].max, sgt[2*i+2].max);
        }
    }

    void pushUp(size_t i, i64 delta) const {
        sgt[i].sum += delta * (sgt[i].r - sgt[i].l + 1);
        sgt[i].max += delta;
        sgt[i].lazy += delta;
    }

    void pushDown(size_t i) const {
        if (sgt[i].l != sgt[i].r) {
            pushUp(2*i+1, sgt[i].lazy);
            pushUp(2*i+2, sgt[i].lazy);
        }
        sgt[i].lazy = 0;
    }

    void add(size_t i, i64 l, i64 r, i64 delta) {
        if (l <= sgt[i].l && r >= sgt[i].r) {
            pushUp(i, delta);
            return;
        }

        pushDown(i);

        i64 mid = sgt[i].l + (sgt[i].r - sgt[i].l) / 2;
        if (l <= mid) {
            add(2*i+1, l, r, delta);
        }
        if (r > mid) {
            add(2*i+2, l, r, delta);
        }

        sgt[i].sum = sgt[2*i+1].sum + sgt[2*i+2].sum;
        sgt[i].max = max(sgt[2*i+1].max, sgt[2*i+2].max);
    }

    i64 askSum(size_t i, i64 l, i64 r) const {
        if (l <= sgt[i].l && r >= sgt[i].r) {
            return sgt[i].sum;
        }

        pushDown(i);

        i64 s = 0;
        i64 mid = sgt[i].l + (sgt[i].r - sgt[i].l) / 2;
        if (l <= mid) {
            s += askSum(2*i+1, l, r);
        }
        if (r > mid) {
            s += askSum(2*i+2, l, r);
        }

        return s;
    }

    i64 askMax(size_t i, i64 l, i64 r) const {
        if (l <= sgt[i].l && r >= sgt[i].r) {
            return sgt[i].max;
        }

        pushDown(i);

        i64 s = numeric_limits<i64>::min();
        i64 mid = sgt[i].l + (sgt[i].r - sgt[i].l) / 2;
        if (l <= mid) {
            s = max(s, askMax(2*i+1, l, r));
        }
        if (r > mid) {
            s = max(s, askMax(2*i+2, l, r));
        }

        return s;
    }
public:
    explicit SegTree(size_t n) : sgt(4 * n) {
        build(0, 0, n-1, [](){return 0;});
    }

    void modify(i64 l, i64 r, i64 delta) {
        add(0, l, r, delta);
    }

    i64 querySum(i64 l, i64 r) const {
        return askSum(0, l, r);
    }

    i64 queryMax(i64 l, i64 r) const {
        return askMax(0, l, r);
    }

    i64 get(i64 i) const {
        return askSum(0, i, i);
    }

    void set(i64 i, i64 value) {
        i64 prev = askSum(0, i, i);
        i64 delta = value - prev;
        add(0, i, i, delta);
    }
};

class TreeMan {
private:
    vector<vector<i64>> tree;
    i64 n;
    vector<i64> fa;
    vector<i64> weight;
    vector<i64> hson;
    vector<i64> dep;
    vector<i64> dfn;
    vector<i64> rnk;
    vector<i64> top;

    void init(i64 i) {
        weight[i] = 1;
        if (fa[i] == -1) dep[i] = 0; else dep[i] = dep[fa[i]] + 1;

        i64 heaviest = -1;
        for (i64 ch : tree[i]) {
            if (ch == fa[i]) continue;
            fa[ch] = i;
            init(ch);
            weight[i] += weight[ch];
            if (heaviest == -1 || weight[ch] > weight[heaviest]) {
                heaviest = ch;
            }
        }

        hson[i] = heaviest;
    }

    void init2(i64 i, i64& cnt) {
        dfn[i] = cnt++;
        rnk[dfn[i]] = i;

        if (hson[i] >= 0) {
            top[hson[i]] = top[i];
            init2(hson[i], cnt);
        }

        for (i64 ch : tree[i]) {
            if (ch == fa[i]) continue;
            if (ch != hson[i]) {
                top[ch] = ch;
                init2(ch, cnt);
            }
        }
    }
public:
    TreeMan(vector<vector<i64>>&& tr) :
        tree(std::move(tr)),
        n(tree.size()), 
        fa(n, -1), 
        weight(n),
        hson(n),
        dep(n),
        dfn(n),
        rnk(n),
        top(n)
    {
        init(0);

        i64 cnt = 0;
        top[0] = 0;
        init2(0, cnt);
    }

    void set(SegTree& sgt, i64 i, i64 v) {
        sgt.set(dfn[i], v);
    }

    i64 lca(i64 u, i64 v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) u = fa[top[u]]; else v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    }

    i64 querySum(const SegTree& sgt, i64 u, i64 v) {
        if (u == v) return sgt.querySum(dfn[u], dfn[v]);

        i64 a = lca(u, v);
        i64 sum = 0;
        while (top[u] != top[a]) {
            sum += sgt.querySum(dfn[top[u]], dfn[u]);
            u = fa[top[u]];
        }
        if (u != a) {
            sum += sgt.querySum(dfn[a], dfn[u]);
        }
        while (top[v] != top[a]) {
            sum += sgt.querySum(dfn[top[v]], dfn[v]);
            v = fa[top[v]];
        }
        if (v != a) {
            sum += sgt.querySum(dfn[a], dfn[v]);
        }
        if (u == a && v == a) {
            sum += sgt.get(dfn[a]);
        }
        return sum;
    }

    i64 queryMax(const SegTree& sgt, i64 u, i64 v) {
        if (u == v) return sgt.queryMax(dfn[u], dfn[v]);

        i64 a = lca(u, v);
        i64 ans = numeric_limits<i64>::min();
        while (top[u] != top[a]) {
            ans = max(ans, sgt.queryMax(dfn[top[u]], dfn[u]));
            u = fa[top[u]];
        }
        if (u != a) {
            ans = max(ans, sgt.queryMax(dfn[a], dfn[u]));
        }
        while (top[v] != top[a]) {
            ans = max(ans, sgt.queryMax(dfn[top[v]], dfn[v]));
            v = fa[top[v]];
        }
        if (v != a) {
            ans = max(ans, sgt.queryMax(dfn[a], dfn[v]));
        }
        if (u == a && v == a) {
            ans = max(ans, sgt.get(dfn[a]));
        }
        return ans;
    }
};

TreeMan readTree(istream& input, i64 n) {
    vector<vector<i64>> tree(n);

    for (i64 i=0; i<n-1; i++) {
        i64 a, b;
        input >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (vector<i64>& nx : tree) {
        sort(nx.begin(), nx.end());
        auto it = unique(nx.begin(), nx.end());
        nx.erase(it, nx.end());
    }

    return TreeMan(std::move(tree));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    TreeMan tr = readTree(cin, n);

    vector<int> weight(n);
    for (int i=0; i<n; i++) cin >> weight[i];

    SegTree sgt(n);
    for (int i=0; i<n; i++) tr.set(sgt, i, weight[i]);

    int q;
    cin >> q;

    while (q--) {
        string opr;
        int u, v;
        cin >> opr;
        cin >> u >> v;
        if (opr == "CHANGE") {
            tr.set(sgt, u-1, v);
        } else if (opr == "QSUM") {
            cout << tr.querySum(sgt, u-1, v-1) << '\n';
        } else if (opr == "QMAX") {
            cout << tr.queryMax(sgt, u-1, v-1) << '\n';
        }
    }

    return 0;
}