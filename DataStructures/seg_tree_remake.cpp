#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

// For closed area
constexpr int overlap_length(int x1, int x2, int y1, int y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    return max(0, min(min(y2-x1+1, x2-y1+1), min(x2-x1+1, y2-y1+1)));
}

template <typename N>
class seg_tree {
private:
    const int size;
    vector<N> heap;
    vector<N> lazy_tag;

    void add_range_internal(int node_index, int l, int r, int left_index, int right_index, N value) {
        int mid = (r-l)/2+l;
        int left_node = (node_index+1)*2-1;
        int right_node = left_node+1;
        
        int left_len = overlap_length(l, mid, left_index, right_index);
        int right_len = overlap_length(mid+1, r, left_index, right_index);

        if (left_len > 1) {
            if (left_len == mid-l+1) {
                lazy_tag[left_node] = lazy_tag[left_node] + value;
            } else {
                add_range_internal(left_node, l, mid, left_index, right_index, value);
            }
        }
        heap[left_node] += value * left_len;

        if (right_len > 1) {
            if (right_len == r-mid && right_len > 1) {
                lazy_tag[right_node] = lazy_tag[right_node] + value;
            } else {
                add_range_internal(right_node, mid+1, r, left_index, right_index, value);
            }
        }
        heap[right_node] += value * right_len;
    }

    N query_range_internal(int node_index, int l, int r, int left_index, int right_index) {
        if (l == r) {
            return heap[node_index];
        }

        int mid = (r-l)/2+l;
        int left_node = (node_index+1)*2-1;
        int right_node = left_node+1;

        if (lazy_tag[node_index] != 0) {
            N tag = lazy_tag[node_index];
            int l_size = mid-l+1;
            int r_size = r-mid;
            heap[left_node] += tag * l_size;
            if (l_size > 1) lazy_tag[left_node] = tag;
            heap[right_node] += tag * r_size;
            if (r_size > 1) lazy_tag[right_node] = tag;

            lazy_tag[node_index] = 0;
        }

        int left_len = overlap_length(l, mid, left_index, right_index);
        int right_len = overlap_length(mid+1, r, left_index, right_index);

        N sum = 0;
        if (left_len > 0) {
            if (left_len == mid-l+1) {
                sum += heap[left_node];
            } else {
                sum += query_range_internal(left_node, l, mid, left_index, right_index);
            }
        }

        if (right_len > 0) {
            if (right_len == r-mid) {
                sum += heap[right_node];
            } else {
                sum += query_range_internal(right_node, mid+1, r, left_index, right_index);
            }
        }

        return sum;
    }
public:
    seg_tree(int size)
        : size(size), heap(4*size), lazy_tag(4*size)
    {}

    void add_single(int index, N value) {
        int node_index = 0;
        int l=0, r=size-1;
        while (l != r) {
            heap[node_index] += value;
            int mid = (r-l)/2+l;
            if (index > mid) {
                l = mid+1;
                node_index = (node_index+1)*2;
            } else {
                r = mid;
                node_index = (node_index+1)*2-1;
            }
        }
        heap[node_index] += value;
    }

    // Add a value in range [left_index, right_index]
    void add_range(int left_index, int right_index, N value) {
        add_range_internal(0, 0, size-1, left_index, right_index, value);
    }

    N query_range(int left_index, int right_index) {
        return query_range_internal(0, 0, size-1, left_index, right_index);
    }

    N query_single(int index) {
        return query_range(index, index);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    seg_tree<i64> sgt(n);

    for (int i=0; i<n; i++) {
        i64 p;
        cin >> p;
        sgt.add_single(i, p);
    }
    
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            i64 k;
            cin >> x >> y >> k;
            x--;
            y--;
            sgt.add_range(x, y, k);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            i64 result = sgt.query_range(x, y);
            cout << result << endl;
        }
    }
    return 0;
}