#include <bits/stdc++.h>

using namespace std;

template <typename T>
class simple_graph {
public:
    simple_graph();

    void clear();
    void connect(const T& a, const T& b);
    bool bitest() const;

    const unordered_set<T>& forward(const T& x) const;
private:
    unordered_map< T, unordered_set<T> > adt;

    bool bitest_internal(
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
bool simple_graph<T>::bitest() const {
    unordered_map<T, char> test;
    for (const pair< T, unordered_set<T> >& p : adt) {
        if (!test.count(p.first)) {
            if (!bitest_internal(test, p.first, 0)) return false;
        }
    }
    return true;
}

template <typename T>
bool simple_graph<T>::bitest_internal(
    unordered_map<T, char> &test,
    const T& node,
    char state
) const {
    test[node] = state;
    for (const T& i : forward(node)) {
        if (!test.count(i)) {
            if (!bitest_internal(test, i, !state)) return false;
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
