#include <iostream>
#include <stdexcept>
#include <memory.h>

using namespace std;
using u64 = unsigned long long;

template <typename T>
class stack {
public:
    stack();
    ~stack();
    template <typename... Args>
    inline void emplace(Args&&... args);
    inline void push(const T& x);
    inline void pop();
    inline const T& top() const;
    inline size_t size() const;
    constexpr bool empty() const;

    inline size_t capacity() const;
    inline void reserve(size_t n);
private:
    T* data_ptr;
    size_t reserved_size;
    size_t used_size;
};

template <typename T>
stack<T>::stack() {
    data_ptr = nullptr;
    reserved_size = 0;
    used_size = 0;
}

template <typename T>
stack<T>::~stack() {
    while (used_size>0) {
        pop();
    }
    if (data_ptr) {
        free(data_ptr);
        data_ptr = nullptr;
    }
}

template <typename T>
void stack<T>::reserve(size_t n) {
    if (n >= used_size) {
        if (n == 0 && data_ptr) {
            free(data_ptr);
        } else if (!data_ptr) {
            data_ptr = (T*)malloc(sizeof(T)*n);
        } else {
            data_ptr = (T*)realloc(data_ptr, sizeof(T)*n);
        }
    }
}

template <typename T>
size_t stack<T>::capacity() const {
    return reserved_size;
}

template <typename T>
size_t stack<T>::size() const {
    return used_size;
}

template <typename T>
const T& stack<T>::top() const {
    if (used_size > 0) {
        return data_ptr[used_size-1];
    } else {
        throw range_error("Stack is empty");
    }
}

template <typename T>
void stack<T>::pop() {
    if (used_size > 0) {
        data_ptr[--used_size].~T();
    } else {
        throw range_error("Stack is empty");
    }
}

template <typename T>
template <typename... Args>
void stack<T>::emplace(Args&&... args) {
    if (reserved_size <= used_size) {
        reserve(size_t(used_size*1.5)+1);
    }
    new (data_ptr + used_size++) T(std::forward<Args>(args)...);
}

template <typename T>
void stack<T>::push(const T& x) {
    emplace(x);
}

template <typename T>
constexpr bool stack<T>::empty() const {
    return used_size == 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        stack<u64> st;
        size_t n;
        cin >> n;
        st.reserve(n);

        while (n--) {
            string operand;
            cin >> operand;

            if (operand == "push") {
                u64 val;
                cin >> val;
                st.push(val);
            } else if (operand == "pop") {
                if (st.empty()) {
                    cout << "Empty" << endl;
                } else {
                    st.pop();
                }
            } else if (operand == "query") {
                if (st.empty()) {
                    cout << "Anguei!" << endl;
                } else {
                    cout << st.top() << endl;
                }
            } else if (operand == "size") {
                cout << st.size() << endl;
            }
        }
    }
    return 0;
}