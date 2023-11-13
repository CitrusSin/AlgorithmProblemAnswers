#include <bits/stdc++.h>
using namespace std;


template <typename T>
class simple_graph {
public:
    simple_graph();

    void clear();
    void connect(const T& a, const T& b);
    bool bi_test() const;

    const unordered_set<T>& forward(const T& x) const;
private:
    unordered_map< T, unordered_set<T> > adt;

    bool bi_test_internal(
        unordered_map<T, char> &test,
        const T& node,
        char state
    ) const;
};

template <typename T>
simple_graph<T>::simple_graph() {
    clear();
}

template <typename T>
void simple_graph<T>::clear() {
    adt.clear();
}

template <typename T>
void simple_graph<T>::connect(const T &a, const T &b) {
    adt[a].insert(b);
    adt[b].insert(a);
}

template <typename T>
bool simple_graph<T>::bi_test() const {
    unordered_map<T, char> test;
    for (const pair< T, unordered_set<T> >& p : adt) {
        if (!test.count(p.first)) {
            if (!bi_test_internal(test, p.first, 0)) return false;
        }
    }
    return true;
}

template <typename T>
bool simple_graph<T>::bi_test_internal(
    unordered_map<T, char> &test,
    const T& node,
    char state
) const {
    test[node] = state;
    for (const T& i : forward(node)) {
        if (!test.count(i)) {
            if (!bi_test_internal(test, i, !state)) return false;
        } else {
            if (test[i] != !state) return false;
        }
    }
    return true;
}

template <typename T>
const unordered_set<T> &simple_graph<T>::forward(const T &x) const {
    return adt.at(x);
}


struct conflict {
    int crime_a;
    int crime_b;
    int amp;
    conflict(int a, int b, int c) {
        crime_a = a;
        crime_b = b;
        amp = c;
    }
    bool operator<(const conflict& c2) const {
        return amp < c2.amp;
    }
    bool operator>(const conflict& c2) const {
        return amp > c2.amp;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> crim_sgn(n, 1);
    vector<conflict> confs;

    confs.reserve(m);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        confs.emplace_back(a, b, c);
    }

    sort(confs.begin(), confs.end(), greater<conflict>());

    int l=0, r=confs.size()-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        simple_graph<int> bg;
        for (int i=0; i<=mid; i++) {
            bg.connect(confs[i].crime_a-1, confs[i].crime_b-1);
        }
        if (bg.bi_test()) {
            l = mid+1;
        } else {
            r = mid;
            if (l == r) break;
        }
    }
    cout << (l<confs.size()?confs[l].amp:0) << endl;
    return 0;
}

