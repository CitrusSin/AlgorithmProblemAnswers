#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

template <typename Num>
struct seg_node {
    Num val;
    Num lazy_tag;
    size_t left;
    size_t right;
};

template <typename Num>
class seg_tree {
public:
    seg_tree(const vector<Num> &vec);
    void add(size_t index, Num differ);
    void add(size_t begin_index, size_t end_index, Num differ);
    Num query(size_t begin_index, size_t end_index);
private:
    size_t list_size;
    vector<seg_node<Num>> heap_vec;

    static void build_seg_heap(vector<seg_node<Num>> &heap_vec, size_t acc_pos, size_t l, size_t r);
    static void heap_modify(vector<seg_node<Num>> &heap_vec, size_t acc_pos, size_t begin_index, size_t end_index, Num differ);
    static Num heap_query(vector<seg_node<Num>> &heap_vec, size_t acc_pos, size_t begin_index, size_t end_index);
};

template <typename Num>
void seg_tree<Num>::build_seg_heap(vector<seg_node<Num>> &heap_vec, size_t acc_pos, size_t l, size_t r) {
    seg_node<Num> &self = heap_vec[acc_pos];
    self.val = 0;
    self.lazy_tag = 0;
    self.left = l;
    self.right = r;

    if (l != r) {
        size_t spliter = l+(r-l)/2;
        seg_tree<Num>::build_seg_heap(heap_vec, (acc_pos<<1)+1, l, spliter);
        seg_tree<Num>::build_seg_heap(heap_vec, (acc_pos<<1)+2, spliter+1, r);
    }
}

template <typename Num>
Num seg_tree<Num>::heap_query(vector<seg_node<Num>> &heap_vec, size_t acc_pos, size_t begin_index, size_t end_index) {
    seg_node<Num> &self = heap_vec[acc_pos];
    if (self.left >= begin_index && self.right <= end_index) {
        return self.val;
    } else if (self.left <= end_index && self.right >= begin_index) {
        if (self.left == self.right) {
            return self.val;
        } else {
            // Downgrad lazy tag
            Num tag = self.lazy_tag;
            self.lazy_tag = 0;
            seg_node<Num> &left_child = heap_vec[(acc_pos<<1)+1], &right_child = heap_vec[(acc_pos<<1)+2];
            left_child.lazy_tag += tag;
            left_child.val += tag * (left_child.right - left_child.left + 1);
            right_child.lazy_tag += tag;
            right_child.val += tag * (right_child.right - right_child.left + 1);
            // Recursive
            Num result = 0;
            result += seg_tree<Num>::heap_query(heap_vec, (acc_pos<<1)+1, begin_index, end_index);
            result += seg_tree<Num>::heap_query(heap_vec, (acc_pos<<1)+2, begin_index, end_index);
            return result;
        }
    }
    return 0;
}

template <typename Num>
void seg_tree<Num>::heap_modify(vector<seg_node<Num>> &heap_vec, size_t acc_pos, size_t begin_index, size_t end_index, Num differ) {
    seg_node<Num> &self = heap_vec[acc_pos];
    if (self.left >= begin_index && self.right <= end_index) {
        if (self.left != self.right)
            self.lazy_tag += differ;
        self.val += differ * (self.right - self.left + 1);
    } else if (self.left <= end_index && self.right >= begin_index) {
        if (self.right - self.left > 0) {
            // Downgrad lazy tag
            Num tag = self.lazy_tag;
            self.lazy_tag = 0;
            seg_node<Num> &left_child = heap_vec[(acc_pos<<1)+1], &right_child = heap_vec[(acc_pos<<1)+2];
            left_child.lazy_tag += tag;
            left_child.val += tag * (left_child.right - left_child.left + 1);
            right_child.lazy_tag += tag;
            right_child.val += tag * (right_child.right - right_child.left + 1);

            size_t count = min(end_index, self.right) - max(begin_index, self.left) + 1;
            self.val += differ * count;
            // Recursive
            seg_tree<Num>::heap_modify(heap_vec, (acc_pos<<1)+1, begin_index, end_index, differ);
            seg_tree<Num>::heap_modify(heap_vec, (acc_pos<<1)+2, begin_index, end_index, differ);
        }
    }
}

template <typename Num>
seg_tree<Num>::seg_tree(const vector<Num> &vec) {
    size_t size = vec.size();

    this->list_size = size;
    this->heap_vec.resize(4*size);

    seg_tree<Num>::build_seg_heap(this->heap_vec, 0, 0, this->list_size-1);
    for (size_t i=0; i<size; i++) {
        seg_tree<Num>::heap_modify(this->heap_vec, 0, i, i, vec[i]);
    }
}

template <typename Num>
void seg_tree<Num>::add(size_t index, Num differ) {
    this->add(index, index, differ);
}

template <typename Num>
void seg_tree<Num>::add(size_t begin_index, size_t end_index, Num differ) {
    seg_tree<Num>::heap_modify(this->heap_vec, 0, begin_index, end_index, differ);
}

template <typename Num>
Num seg_tree<Num>::query(size_t begin_index, size_t end_index) {
    return seg_tree<Num>::heap_query(this->heap_vec, 0, begin_index, end_index);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    seg_tree<long long> seg(arr);

    for (int i=0; i<m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            size_t x, y;
            long long k;
            cin >> x >> y >> k;
            seg.add(x-1, y-1, k);
        } else if (op == 2) {
            size_t x, y;
            cin >> x >> y;
            cout << seg.query(x-1, y-1) << endl;
        }
    }
    return 0;
}