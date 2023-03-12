#include <bits/stdc++.h>

using namespace std;

void extgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    extgcd(b, a%b, x, y);
    int64_t tmp = x;
    x = y;
    y = tmp-(a/b)*y;
}

template <int64_t M>
class Mod {
public:
    Mod() : value(0) {}
    Mod(int64_t val) : value(val%M) {};

    Mod<M> inv() const {
        int64_t x, y;
        extgcd(value, M, x, y);
        bool neg_flag = x<0;
        if (neg_flag) x=-x;
        x %= M;
        if (neg_flag) x=M-x;
        return Mod<M>(x);
    }

    operator int64_t() const {return value;}

    Mod<M>& operator+=(const Mod<M>& val) {
        value += val.value;
        value %= M;
        return *this;
    }
    Mod<M> operator-() const {return Mod<M>(M-value);}
    Mod<M>& operator-=(const Mod<M>& val) {return (*this)+=(-val);}

    Mod<M> operator+(const Mod<M>& val) const {
        Mod<M> x2 = (*this);
        return x2 += val;
    }
    Mod<M> operator-(const Mod<M>& val) const {
        Mod<M> x2 = (*this);
        return x2 -= val;
    }

    Mod<M>& operator*=(const Mod<M>& val) {
        value *= val.value;
        value %= M;
        return *this;
    }
    Mod<M> operator*(const Mod<M>& val) const {
        Mod<M> x2 = (*this);
        return x2 *= val;
    }

    Mod<M>& operator/=(const Mod<M>& val) {return (*this)*=val.inv();}
    Mod<M> operator/(const Mod<M>& val) const {
        Mod<M> x2 = (*this);
        return x2 /= val;
    }
private:
    int64_t value;
};

template <size_t N, size_t M, typename Num>
class Matrix {
public:
    Matrix() : arr() {}
    Matrix(initializer_list<initializer_list<Num>> &&lst) {
        auto itb = lst.begin();
        for (size_t i=0; i<N; i++) {
            auto it2 = (*itb++).begin();
            for (size_t j=0; j<M; j++) {
                arr[i][j] = (*it2++);
            }
        }
    }
    Matrix(array<array<Num, M>, N> &&arr) : arr(arr) {}

    const array<Num, M>& operator[](size_t i) const {
        return arr[i];
    }
    array<Num, M>& operator[](size_t i) {
        return arr[i];
    }

    template <size_t K>
    Matrix<N, K, Num> operator*(const Matrix<M, K, Num>& mat2) const {
        array<array<Num, K>, N> result;
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<K; j++) {
                result[i][j] = 0;
                for (size_t k=0; k<M; k++) {
                    result[i][j] += arr[i][k] * mat2.arr[k][j];
                }
            }
        }
        return Matrix<N, K, Num>(std::move(result));
    }
private:
    array<array<Num, M>, N> arr;
};

template <size_t N, typename Num>
class Matrix<N, N, Num> {
public:
    Matrix() : arr() {}
    Matrix(initializer_list<initializer_list<Num>> &&lst) {
        auto itb = lst.begin();
        for (size_t i=0; i<N; i++) {
            auto it2 = (*itb++).begin();
            for (size_t j=0; j<N; j++) {
                arr[i][j] = (*it2++);
            }
        }    
    }
    Matrix(array<array<Num, N>, N> &&arr) : arr(arr) {}
    Matrix(Num val) {
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<N; j++) {
                if (i != j)
                    arr[i][j] = 0;
                else
                    arr[i][j] = val;
            }
        }
    }

    const array<Num, N>& operator[](size_t i) const {
        return arr[i];
    }
    array<Num, N>& operator[](size_t i) {
        return arr[i];
    }

    template <size_t K>
    Matrix<N, K, Num> operator*(const Matrix<N, K, Num>& mat2) const {
        array<array<Num, K>, N> result;
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<K; j++) {
                result[i][j] = 0;
                for (size_t k=0; k<N; k++) {
                    result[i][j] += arr[i][k] * mat2.arr[k][j];
                }
            }
        }
        return Matrix<N, K, Num>(std::move(result));
    }
private:
    array<array<Num, N>, N> arr;
};

const int64_t MOD = 998244353;

template <typename Num>
Num qpow(Num base, int64_t power) {
    if (power == 0) return Num(1);
    if (power == 1) return base;

    Num r = qpow(base, power/2);
    if (power%2==0)
        return r*r;
    else
        return r*r*base;
}

int main() {
    Matrix<2, 2, Mod<MOD>> mat = {{1, 1}, {1, 0}};
    auto mat2 = qpow(mat, 2);

    return 0;
}