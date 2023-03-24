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

// Discrete disjoint set
// Encapsulated from dset_raw
// head(x): return head element in the group of x
// merge(a, b): merge the group containing a and the group containing b
// query(a, b): return whether a and b is in the same group
// count_set(): count how much groups exist in the data structure
// sign(x): Sign x as a single element as well as a single group in the data structure
template <typename T>
class disset {
public:
    const T& head(const T& elem) const;
    void merge(const T& a, const T& b);
    bool query(const T& a, const T& b) const;

    int count_set() const;
    bool contains(const T& x) const;

    inline void sign(const T& x);
private:
    dset_raw raw_set;
    unordered_map<T, int> index_map;
    vector<T> index_rev_map;
};

template <typename T>
const T &disset<T>::head(const T &elem) const {
    if (index_map.count(elem)) {
        int idx = index_map.at(elem);
        return index_rev_map[raw_set.head(idx)];
    } else return elem;
}

template <typename T>
void disset<T>::merge(const T &a, const T &b) {
    sign(a);
    sign(b);
    raw_set.merge(index_map[a], index_map[b]);
}

template <typename T>
bool disset<T>::query(const T &a, const T &b) const {
    try {
        return raw_set.query(index_map.at(a), index_map.at(b));
    } catch(...) {
        return false;
    }
}

template <typename T>
int disset<T>::count_set() const {
    return raw_set.count_set();
}

template <typename T>
void disset<T>::sign(const T &x) {
    if (!index_map.count(x)) {
        index_map[x] = index_rev_map.size();
        index_rev_map.push_back(x);
        raw_set.expand(index_rev_map.size());
    }
}

template <typename T>
bool disset<T>::contains(const T &x) const {
    return index_map.count(x)?true:false;
}

template <typename T, size_t N>
int array_find(const array<T, N>& arr, const T& val) {
    for (size_t i=0; i<N; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    disset<int> s;
    //int head_chain[3] = {-1, -1, -1};
    array<int, 3> head_chain = {-1, -1, -1};
    int head_len = 0, fake_cnt = 0;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        switch (d) {
        case 1:
            if (!s.contains(x) && s.contains(y)) {
                s.merge(y, x);
            } else if (!s.contains(y)) {
                s.merge(x, y);
            } else if (s.contains(x) && s.contains(y)) {
                if (!s.query(x, y)) {
                    int a = s.head(x), b = s.head(y);
                    if (array_find(head_chain, a)>=0 && array_find(head_chain, b)>=0) {
                        fake_cnt++;
                    } else {
                        if (array_find(head_chain, b)) swap(a, b);
                        s.merge(a, b);
                    }
                }
            }
            break;
        case 2:
            s.sign(x);
            s.sign(y);
            int a = s.head(x), b = s.head(y);
            if (a == b) {
                fake_cnt++;
            } else {
                int aidx = array_find(head_chain, a), bidx = array_find(head_chain, b);
                if (aidx == -1 && bidx == -1) {
                    
                } else if (aidx == -1) {
                    if (head_chain[(bidx-1)%3] == -1) {
                        if (head_len == 3) {
                            fake_cnt++;
                        } else {
                            head_len++;
                            head_chain[(bidx-1)%3] = a;
                        }
                    } else {
                        s.merge(head_chain[(bidx-1)%3], a);
                    }
                } else if (bidx == -1) {
                    if (head_chain[(aidx+1)%3] == -1) {
                        if (head_len == 3) {
                            fake_cnt++;
                        } else {
                            head_len++;
                            head_chain[(aidx+1)%3] = b;
                        }
                    } else {
                        s.merge(head_chain[(aidx+1)%3], b);
                    }
                } else {
                    if ((aidx+1)%3!=bidx) {
                        fake_cnt++;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

