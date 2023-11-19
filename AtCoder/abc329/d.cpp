#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>

template <typename T, typename U, typename Id, typename Comp>
void adjust_heap(T& heap, U& qrs, Id idf, size_t len, size_t idx, Comp le) {
    // Judge father
    if (idx == 0) return;
    size_t fa = (idx + 1) / 2 - 1;
    if (le(heap[idx], heap[fa])) {
        std::swap(heap[idx], heap[fa]);
        qrs[idf(heap[idx])] = idx;
        qrs[idf(heap[fa])] = fa;
        adjust_heap(heap, qrs, idf, len, fa, le);
    }
}

template <typename T, typename U, typename Id, typename Comp>
void insert_heap(T& heap, U& qrs, Id idf, size_t len, Comp le) {
    //heap[len] = value;
    size_t pos = len, fa = (len+1)/2-1;
    while (pos > 0 && le(heap[pos], heap[fa])) {
        std::swap(heap[pos], heap[fa]);
        qrs[idf(heap[pos])] = pos;
        qrs[idf(heap[fa])] = fa;
        pos = fa;
        fa = (pos+1)/2-1;
    }
}

template <typename T, typename U, typename Id, typename Comp>
void make_heap(T& heap, U& qrs, Id idf, size_t len, Comp le) {
    for (size_t i=1; i<len; i++) {
        insert_heap(heap, qrs, idf, i, le);
    }
}

template <typename T, typename U, typename Id, typename Comp>
T pop_heap(T& heap, U& qrs, Id idf, size_t len, Comp le) {
    T value = heap[0];
    size_t idx = 0;
    while (2*idx+1 < len) {
        size_t ch1 = 2*idx+1, ch2 = 2*idx+2;
        bool use_ch2 = ch2 < len && le(heap[ch2], heap[ch1]);
        if (use_ch2) {
            std::swap(heap[idx], heap[ch2]);
            qrs[idf(heap[idx])] = idx;
            qrs[idf(heap[ch2])] = ch2;
            idx = ch2;
        } else {
            std::swap(heap[idx], heap[ch1]);
            qrs[idf(heap[idx])] = idx;
            qrs[idf(heap[ch1])] = ch1;
            idx = ch1;
        }
    }
    std::swap(heap[len-1], heap[idx]);
    adjust_heap(heap, qrs, idf, len-1, idx, le);
}

struct Candidate {
    int id;
    int vote;
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Candidate> cands(n);
    for (int i=0; i<n; i++) {
        cands[i].id = i;
        cands[i].vote = 0;
    }

    std::vector<int> sidx(n);
    for (int i=0; i<n; i++) {
        sidx[i] = i;
    }

    auto comp = [](Candidate& c1, Candidate& c2) {
        if (c1.vote > c2.vote) return true;
        if (c1.vote < c2.vote) return false;
        return c1.id < c2.id;
    };

    auto idf = [](Candidate& c) {return c.id;};

    make_heap(cands, sidx, idf, n, comp);
    
    for (int i=0; i<m; i++) {
        int a;
        std::cin >> a;

        int idx = sidx[a-1];
        cands[idx].vote++;
        adjust_heap(cands, sidx, idf, n, idx, comp);

        std::cout << (cands[0].id + 1) << std::endl;
    }
    return 0;
}