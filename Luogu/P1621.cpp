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
// head(elem): return head element in the group of elem
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
        return raw_set.query(index_map[a], index_map[b]);
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

// O(sqrt(x)/log(x)), Assuming prev_primes contains all primes less than x
static inline bool check_prime(const vector<int>& prev_primes, int x) {
    int upper_lim = floor(sqrtf64(x));
    for (int i : prev_primes) {
        if (i > upper_lim) {
            return true;
        } else if (x%i==0) {
            return false;
        }
    }
    return true;
}

// O((upper_lim-primes.size())*(sqrt(upper_lim)/log(upper_lim)) = O((n-n0)sqrt(n)/log(n))
// O(n^1.5/log(n)) when generate from empty, with a constant time multiplier 1/3
void prime_generate(vector<int>& primes, int upper_lim) {
    if (primes.size() < 3) {
        primes.assign({2, 3, 5});
    }
    int k = primes.back()-1;
    if ((primes.back()+1)%6==0) {
        k = primes.back()+1;
        if (check_prime(primes, k+1)) {
            primes.push_back(k+1);
        }
    }
    k /= 6;
    k++;
    
    while (true) {
        int n1 = k*6-1, n2 = n1+2;
        if (n1 > upper_lim) break;
        if (check_prime(primes, n1)) {
            primes.push_back(n1);
        }
        if (n2 > upper_lim) break;
        if (check_prime(primes, n2)) {
            primes.push_back(n2);
        }
        k++;
    }
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;

    vector<int> primes;
    prime_generate(primes, b);

    auto iter = lower_bound(primes.begin(), primes.end(), p);

    disset<int> dst;
    for (int i=a; i<=b; i++) {
        dst.sign(i);
    }
    while (iter != primes.end()) {
        int p = *iter;
        int max_k = b / p, min_k = a / p;
        if (a%p) min_k++;
        for (int k=min_k; k<=max_k; k++) {
            dst.merge(p, p*k);
        }
        iter++;
    }

    cout << dst.count_set() << endl;
    return 0;
}
