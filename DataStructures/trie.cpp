#include <bits/stdc++.h>
using namespace std;

template <typename T>
class trie {
public:
    class const_iterator {
    public:
        const_iterator() = delete;

        const_iterator& operator++() {
            ++base_iter;
            return *this;
        };
        bool operator!=(const const_iterator& i2) {
            return i2.base_iter != base_iter;
        };
        const trie<T> & operator*() {
            return **base_iter;
        };
    private:
        typename vector<trie<T> *>::const_iterator base_iter;

        friend const_iterator trie<T>::begin() const;
        friend const_iterator trie<T>::end() const;
        const_iterator(typename vector<trie<T> *>::const_iterator iter) {
            base_iter = iter;
        }
    };

    trie() {
        is_root = true;
    }

    template <typename Iterator>
    trie(Iterator it_begin, Iterator it_end) {
        add(it_begin, it_end);
        is_root = true;
    }

    ~trie() {
        for (trie<T> *node : sub_nodes) {
            if (node && (!node->is_root)) {
                delete node;
            }
        }
    }

    trie<T> & operator=(const trie<T>& t2) = delete;
    trie(const trie<T>& t2) = delete;

    template <typename Container>
    void add(const Container& init_list) {
        add(cbegin(init_list), cend(init_list));
    }
    
    template <typename Iterator>
    void add(Iterator it_begin, Iterator it_end) {
        if (it_begin != it_end) {
            bool found = false;
            for (trie<T> *node : sub_nodes) {
                if (node->element == *it_begin) {
                    node->add(++it_begin, it_end);
                    found = true;
                    break;
                }
            }
            if (!found) {
                sub_nodes.push_back(new trie<T>(*it_begin, false));
                trie<T> *ptr = sub_nodes.back();
                ptr->add(++it_begin, it_end);
            }
        } else if (!is_root) {
            end_count++;
        }
    }

    void set(const T& element) {
        this->element = element;
    }

    template <typename Container>
    size_t query(const Container& init_list) const {
        return query(cbegin(init_list), cend(init_list));
    }

    template <typename Iterator>
    size_t query(Iterator it_begin, Iterator it_end) const {
        if (it_begin != it_end) {
            for (trie<T> *node : sub_nodes) {
                if (node->element == *it_begin) {
                    return query(node->query(++it_begin, it_end));
                }
            }
            return 0;
        } else if (!is_root) {
            return end_count;
        } else {
            return 0;
        }
    }

    bool contains_next(const T& element) const {
        for (trie<T> *node : sub_nodes) {
            if (node->element == element) {
                return true;
            }
        }
        return false;
    }

    T& operator*() {
        return element;
    }

    const T& operator*() const {
        return element;
    }

    const_iterator begin() const {
        return const_iterator(sub_nodes.cbegin());
    }

    const_iterator end() const {
        return const_iterator(sub_nodes.cend());
    }

    const trie<T> & operator[](const T& index) const {
        for (const trie<T> *node : sub_nodes) {
            if (node->element == index) {
                return *node;
            }
        }
        throw std::range_error("Trie doesn't contains a specified value");
    }

    bool empty() const {
        return sub_nodes.empty();
    }

    size_t node_count() const {
        return sub_nodes.size();
    }

    bool root() const {
        return is_root;
    }
private:
    bool is_root = true;
    size_t end_count = 0;
    T element;
    vector<trie<T> *> sub_nodes;

    trie(const T& element, bool is_root) {
        set(element);
        this->is_root = is_root;
    };
};
