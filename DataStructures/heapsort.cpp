#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

template <typename T>
class BinaryHeap {
public:
    BinaryHeap();
    explicit BinaryHeap(size_t size);
    explicit BinaryHeap(const function<bool(T&, T&)> &comparator);
    BinaryHeap(size_t size, const function<bool(T&, T&)> &comparator);

    void insert(const T &val);
    T takeMin();
    [[nodiscard]] const T &peekMin() const;
    void resize(size_t size);
    [[nodiscard]] size_t space() const;
    [[nodiscard]] size_t size() const;
private:
    vector<T> heapArr;
    size_t realSize;
    function<bool(T&, T&)> comparator;
};

template <typename T>
BinaryHeap<T>::BinaryHeap() {
    new (this) BinaryHeap([](T &a, T &b){return a<b;});
}

template <typename T>
BinaryHeap<T>::BinaryHeap(size_t size) {
    new (this) BinaryHeap(size, [](T &a, T &b){return a<b;});
}

template <typename T>
BinaryHeap<T>::BinaryHeap(const function<bool(T&, T&)> &comp) {
    comparator = comp;
    realSize = 0;
    resize(0);
}

template <typename T>
BinaryHeap<T>::BinaryHeap(size_t size, const function<bool(T&, T&)> &comp) {
    comparator = comp;
    realSize = 0;
    resize(size);
}

template <typename T>
void BinaryHeap<T>::resize(size_t size) {
    heapArr.resize(size);
}

template <typename T>
size_t BinaryHeap<T>::space() const {
    return heapArr.size();
}

template <typename T>
size_t BinaryHeap<T>::size() const {
    return realSize;
}

template <typename T>
void BinaryHeap<T>::insert(const T &val) {
    if (realSize == 0) {
        if (heapArr.size() > 0) {
            heapArr[0] = val;
        } else {
            heapArr.push_back(val);
        }
        realSize++;
    } else {
        size_t accessIndex = realSize;
        if (heapArr.size() <= realSize+1) {
            heapArr.resize(realSize+10);
        }
        heapArr[accessIndex] = val;
        // Percolate up
        while (accessIndex > 0 && comparator(heapArr[accessIndex], heapArr[((accessIndex+1)>>1)-1])) {
            T &a = heapArr[accessIndex], &b = heapArr[((accessIndex+1)>>1)-1];
            T sw = a;
            a = b;
            b = sw;
            accessIndex = ((accessIndex+1)>>1)-1;
        }
        realSize++;
    }
}

template <typename T>
T BinaryHeap<T>::takeMin() {
    size_t accessIndex = 0;
    size_t li = accessIndex*2+1, ri = accessIndex*2+2;
    while (ri < realSize) {
        if (comparator(heapArr[li], heapArr[ri])) {
            T &a = heapArr[accessIndex], &b = heapArr[li];
            T sw = a;
            a = b;
            b = sw;
            accessIndex = li;
        } else {
            T &a = heapArr[accessIndex], &b = heapArr[ri];
            T sw = a;
            a = b;
            b = sw;
            accessIndex = ri;
        }
        li = accessIndex*2+1;
        ri = accessIndex*2+2;
    }

    T value = heapArr[accessIndex];
    heapArr[accessIndex] = heapArr[realSize-1];
    realSize--;
    return value;
}

template <typename T>
const T &BinaryHeap<T>::peekMin() const {
    return heapArr[0];
}

template <typename Iter>
void heapSort(Iter b, Iter e, const function<bool(typename iterator_traits<Iter>::value_type&, typename iterator_traits<Iter>::value_type&)> &comparator) {
    using T = typename iterator_traits<Iter>::value_type;
    BinaryHeap<T> heap(e - b, comparator);

    Iter it = b;
    while (it < e) {
        heap.insert(*it);
        ++it;
    }

    it = b;
    while (it < e) {
        *it = heap.takeMin();
        ++it;
    }
}

template <typename Iter>
void heapSort(Iter e, Iter b) {
    using T = typename iterator_traits<Iter>::value_type;
    heapSort(e, b, [](T &a, T &b){return a<b;});
}

struct Student {
    string name;
    int score;
};

int main() {
    int n;
    cin >> n;

    Student stus[n];
    for (int i=0; i<n; i++) {
        cin >> stus[i].name >> stus[i].score;
    }

    heapSort(stus+0, stus+n, [](Student &a, Student &b) {return a.score > b.score;});

    for (int i=0; i<n; i++) {
        cout << stus[i].name << " " << stus[i].score << endl;
    }
    return 0;
}