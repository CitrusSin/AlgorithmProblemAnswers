#include <concepts>
#include <functional>
#include <iostream>
#include <vector>

template <typename T, auto Op, auto Mul, T zero_val = T()>
requires
    std::convertible_to<decltype(Op), std::function<T(T, T)>> &&
    std::convertible_to<decltype(Mul), std::function<T(T, size_t)>>
class seg_tree_lazy {
public:
    seg_tree_lazy(size_t n) : tree(4*n), lazy(4*n), len(n) {
        init(0, 0, n-1);
    }

    void add(size_t l, size_t r, const T& value) {
        modify(0, 0, len-1, l, r, value);
    }

    T range(size_t l, size_t r) {
        return query(0, 0, len-1, l, r);
    }
private:
    std::vector<T> tree, lazy;
    size_t len;

    void init(size_t idx, size_t l, size_t r) {
        tree[idx] = zero_val;
        lazy[idx] = zero_val;

        if (l < r) {
            size_t mid = l + (r - l) / 2;
            init(idx*2+1, l, mid);
            init(idx*2+2, mid+1, r);
        }
    }

    void pushup(size_t idx, size_t nl, size_t nr, const T& delta) {
        tree[idx] = Op(tree[idx], Mul(delta, nr - nl + 1));
        lazy[idx] = Op(lazy[idx], delta);
    }

    void pushdown(size_t idx, size_t nl, size_t nr) {
        if (nr > nl) {
            size_t mid = nl + (nr - nl) / 2;
            pushup(idx*2+1, nl, mid, lazy[idx]);
            pushup(idx*2+2, mid+1, nr, lazy[idx]);
        }
        lazy[idx] = zero_val;
    }

    void modify(size_t idx, size_t nl, size_t nr, size_t l, size_t r, const T& delta) {
        if (l <= nl && nr <= r) {
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

        tree[idx] = Op(tree[idx*2+1], tree[idx*2+2]);
    }

    T query(size_t idx, size_t nl, size_t nr, size_t l, size_t r) {
        if (l <= nl && nr <= r) {
            return tree[idx];
        }

        pushdown(idx, nl, nr);

        size_t mid = nl + (nr - nl) / 2;
        T ans = zero_val;
        if (l <= mid) {
            ans = Op(ans, query(idx*2+1, nl, mid, l, r));
        }
        if (r > mid) {
            ans = Op(ans, query(idx*2+2, mid+1, nr, l, r));
        }

        return ans;
    }
};

template <typename T>
using additive_seg_tree_lazy = seg_tree_lazy<T, [](T a, T b){return a+b;}, [](T a, size_t m){return m*a;}>;

template <typename T>
using max_seg_tree_lazy = seg_tree_lazy<T, [](T a, T b){return std::max(a, b);}, [](T a, size_t m){return a;}>;

int main() {
    additive_seg_tree_lazy<int> sgt(20);
    sgt.add(0, 5, 3);
    sgt.add(4, 8, 5);
    std::cout << sgt.range(0, 8) << std::endl;
    std::cout << sgt.range(4, 5) << std::endl;
}