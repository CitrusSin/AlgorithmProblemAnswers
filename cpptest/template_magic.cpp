#include <iostream>

using namespace std;

template <size_t N>
struct factorial {
    static const size_t value = N*factorial<N-1>::value;
    operator size_t() {
        return value;
    };
};
template <>
struct factorial<0> {
    static const size_t value = 1;
    operator size_t() {
        return value;
    };
};

template <size_t N>
constexpr size_t fibonacci() {
    return fibonacci<N-1>() + fibonacci<N-2>();
}

template <>
constexpr size_t fibonacci<0>() {
    return 0;
}

template <>
constexpr size_t fibonacci<1>() {
    return 1;
}

int main() {
    cout << "10! = " << factorial<10>() << endl;
    cout << "fibonacci(12) = " << fibonacci<13>() << endl;
    return 0;
}