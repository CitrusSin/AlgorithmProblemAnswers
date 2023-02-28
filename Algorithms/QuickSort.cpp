#include <iostream>
#include <vector>

using namespace std;

template<typename T>
inline void swap_var(T &a, T &b) {
    T s = a;
    a = b;
    b = s;
}

template<typename RAIter, typename Compare>
void insertion_sort(RAIter begin, RAIter end, Compare comparator) {
    for (RAIter i = begin + 1; i < end; i++) {
        for (RAIter j = i - 1; j >= begin; j--) {
            if (!comparator(*j, *(j+1))) {
                swap_var(*(j+1), *j);
            } else {
                break;
            }
        }
    }
}

template <typename RAIter, typename Compare>
void quick_sort(RAIter begin, RAIter end, Compare comparator) {
    int len = end - begin;
    
    // Cut off and switch to insertion sort
    if (len < 5) {
        insertion_sort(begin, end, comparator);
        return;
    }
    RAIter mid = begin + (len-1)/2, i = begin, j = end;
    if (!comparator(*i, *mid)) {
        swap_var(*i, *mid);
    }
    if (!comparator(*mid, *(end-1))) {
        swap_var(*mid, *(end-1));
    }
    if (!comparator(*i, *mid)) {
        swap_var(*i, *mid);
    }

    // Hide pivot
    auto pivot = *mid;
    swap_var(*mid, *i);

    for (;;) {
        while (comparator(*(++i), pivot) && (*i != pivot));
        while (comparator(pivot, *(--j)) && (*j != pivot));
        if (i < j) {
            swap_var(*i, *j);
        } else break;
    }

    // Restore pivot
    swap_var(*begin, *j);

    // Recursive
    quick_sort(begin, j, comparator);
    quick_sort(j+1, end, comparator);
}

template <typename RAIter>
void quick_sort(RAIter begin, RAIter end) {
    quick_sort(begin, end, std::less());
}

int main() {
    std::vector<int> a = {2, 4, 1, 5, 7, 6, 3};
    quick_sort(a.begin(), a.end());
    
    for (auto iter = a.begin(); iter < a.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    std::vector<double> b = {2., 4., 1., 5., 7., 6., 3.};
    quick_sort(b.begin(), b.end());
    
    for (auto iter = b.begin(); iter < b.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    int c[7] = {6, 7, 5, 1, 2, 4, 3};
    quick_sort(c, c+7);
    for (int i=0; i<7; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}