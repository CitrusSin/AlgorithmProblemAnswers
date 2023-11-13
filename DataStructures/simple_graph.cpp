#include <bits/stdc++.h>

using namespace std;

template < typename T, typename ADSet = set<T>, typename ADMap = map<T, ADSet> >
class simple_graph {
public:
    class iterator {
    public:
        using map_iter = typename ADMap::const_iterator;

        iterator() = delete;
        iterator(map_iter it);
        const T& operator*();
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& i);
        bool operator!=(const iterator& i);
    private:
        map_iter iter;
    };

    simple_graph();
    simple_graph(const initializer_list< pair<T, T> >& lst);

    void clear();
    void connect(const T& a, const T& b);
    bool bitest() const;

    const ADSet& forward(const T& x) const;

    iterator begin() const;
    iterator end() const;
private:
    ADMap adt;

    bool bitest_internal(
        unordered_map<T, char> &test,
        const T& node,
        char state
    ) const;
};

template < typename T, typename ADSet, typename ADMap >
simple_graph<T, ADSet, ADMap>::simple_graph() {
    clear();
}

template < typename T, typename ADSet, typename ADMap >
void simple_graph<T, ADSet, ADMap>::clear() {
    adt.clear();
}

template < typename T, typename ADSet, typename ADMap >
void simple_graph<T, ADSet, ADMap>::connect(const T &a, const T &b) {
    adt[a].insert(b);
    adt[b].insert(a);
}

template < typename T, typename ADSet, typename ADMap >
simple_graph<T, ADSet, ADMap>::simple_graph(const initializer_list< pair<T, T> >& lst) {
    for (const pair<T, T>& ref : lst) {
        connect(ref.first, ref.second);
    }
}

template < typename T, typename ADSet, typename ADMap >
bool simple_graph<T, ADSet, ADMap>::bitest() const
{
    unordered_map<T, char> test;
    for (const auto& p : adt) {
        if (!test.count(p.first)) {
            if (!bitest_internal(test, p.first, 0)) return false;
        }
    }
    return true;
}

template < typename T, typename ADSet, typename ADMap >
typename simple_graph<T, ADSet, ADMap>::iterator simple_graph<T, ADSet, ADMap>::begin() const {
    return simple_graph<T, ADSet, ADMap>::iterator(adt.begin());
}

template < typename T, typename ADSet, typename ADMap >
typename simple_graph<T, ADSet, ADMap>::iterator simple_graph<T, ADSet, ADMap>::end() const {
    return simple_graph<T, ADSet, ADMap>::iterator(adt.end());
}

template < typename T, typename ADSet, typename ADMap >
bool simple_graph<T, ADSet, ADMap>::bitest_internal(
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

template < typename T, typename ADSet, typename ADMap >
const ADSet &simple_graph<T, ADSet, ADMap>::forward(const T &x) const {
    return adt.at(x);
}

template < typename T, typename ADSet, typename ADMap >
simple_graph<T, ADSet, ADMap>::iterator::iterator(map_iter it) {
    iter = it;
}

template < typename T, typename ADSet, typename ADMap >
const T &simple_graph<T, ADSet, ADMap>::iterator::operator*() {
    return iter->first;
}

template < typename T, typename ADSet, typename ADMap >
typename simple_graph<T, ADSet, ADMap>::iterator& simple_graph<T, ADSet, ADMap>::iterator::operator++() {
    ++iter;
    return *this;
}

template < typename T, typename ADSet, typename ADMap >
typename simple_graph<T, ADSet, ADMap>::iterator simple_graph<T, ADSet, ADMap>::iterator::operator++(int) {
    simple_graph<T, ADSet, ADMap>::iterator it = *this;
    ++iter;
    return it;
}

template < typename T, typename ADSet, typename ADMap >
bool simple_graph<T, ADSet, ADMap>::iterator::operator==(const iterator &i) {
    return iter == i.iter;
}

template < typename T, typename ADSet, typename ADMap >
bool simple_graph<T, ADSet, ADMap>::iterator::operator!=(const iterator &i) {
    return iter != i.iter;
}

int main() {
    simple_graph<int> graph = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
    for (int p : graph) {
        cout << p << ": ";
        for (int q : graph.forward(p)) {
            cout << q << " ";
        }
        cout << endl;
    }
    cout << (graph.bitest()?"true":"false") << endl;
    return 0;
}