#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using i64 = int64_t;

void extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x=1;
        y=0;
        return;
    }
    extgcd(b, a%b, x, y);
    i64 tmp = y;
    y = x-(a/b)*y;
    x = tmp;
}

i64 gcd(i64 a, i64 b) {
    return b?gcd(b, a%b):a;
}

template <size_t M>
struct Mod {
    i64 num;
    Mod() : num(0) {}
    Mod(i64 n) : num(n%M) {}

    Mod<M> inv() const {
        if (gcd(num, M) != 1) throw logic_error("Inverse does not exist!");
        i64 x, y;
        extgcd(num, M, x, y);
        x %= (i64)M;
        if (x < 0) x+=M;
        return Mod<M>(x);
    }

    Mod<M> operator+(const Mod<M>& x) const {
        return Mod<M>((num+x.num)%M);
    }
    Mod<M>& operator+=(const Mod<M>& x) {
        num += x.num;
        num %= M;
        return *this;
    }
    Mod<M> operator-() const {
        return Mod<M>(M-num);
    }
    Mod<M> operator-(const Mod<M>& x) const {
        return (*this)+(-x);
    }
    Mod<M>& operator-=(const Mod<M>& x) {
        return (*this) += -x;
    }
    Mod<M> operator*(const Mod<M>& x) const {
        return Mod<M>(x.num*num%M);
    }
    Mod<M>& operator*=(const Mod<M>& x) {
        num *= x.num;
        num %= M;
        return *this;
    }
    Mod<M> operator/(const Mod<M>& x) {
        return (*this) * x.inv();
    }
    Mod<M>& operator/=(const Mod<M>& x) {
        return (*this) *= x.inv();
    }
    operator i64() const {
        return num;
    }
};

template <typename Num, size_t N, size_t M>
class Matrix {
public:
    Matrix() {}

    Matrix(const initializer_list<initializer_list<Num>>& dl) {
        auto iti = dl.begin();
        for (size_t i=0; i<N; i++) {
            const initializer_list<Num>& l2 = *iti++;
            auto itj = l2.begin();
            for (size_t j=0; j<M; j++) {
                mat[i][j] = *itj++;
            }
        }
    }

    const array<Num, M>& operator[](size_t n) const {
        return mat[n];
    }

    array<Num, M>& operator[](size_t n) {
        return mat[n];
    }

    template <size_t K>
    Matrix<Num, N, K> operator*(const Matrix<Num, M, K>& mat2) const {
        Matrix<Num, N, K> res;
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<K; j++) {
                res[i][j] = 0;
                for (size_t k=0; k<M; k++) {
                    res[i][j] += mat[i][k]*mat2[k][j];
                }
            }
        }
        return res;
    }
private:
    array<array<Num, M>, N> mat;
};

template <typename Num, size_t N>
class Matrix<Num, N, N> {
public:
    Matrix() {}

    Matrix(Num n) {
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<N; j++) {
                mat[i][j] = (i==j)?n:Num(0);
            }
        }
    }

    Matrix(int n) {
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<N; j++) {
                mat[i][j] = (i==j)?Num(n):Num(0);
            }
        }
    }

    Matrix(const initializer_list<initializer_list<Num>>& dl) {
        auto iti = dl.begin();
        for (size_t i=0; i<N; i++) {
            const initializer_list<Num>& l2 = *iti++;
            auto itj = l2.begin();
            for (size_t j=0; j<N; j++) {
                mat[i][j] = *itj++;
            }
        }
    }

    const array<Num, N>& operator[](size_t n) const {
        return mat[n];
    }

    array<Num, N>& operator[](size_t n) {
        return mat[n];
    }

    template <size_t K>
    Matrix<Num, N, K> operator*(const Matrix<Num, N, K>& mat2) const {
        Matrix<Num, N, K> res;
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<K; j++) {
                res[i][j] = 0;
                for (size_t k=0; k<N; k++) {
                    res[i][j] += mat[i][k]*mat2[k][j];
                }
            }
        }
        return res;
    }

    Num det() const {
        array<array<Num, N>, N> arr = mat;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                Num co = arr[i][j]/arr[i][i];
                for (int k=i; k<N; k++) {
                    arr[j][k] -= co * arr[i][k];
                }
            }
        }
        Num res = 1;
        for (int i=0; i<N; i++) res *= arr[i][i];
        return res;
    }
private:
    array<array<Num, N>, N> mat;
};

template<typename Num>
Num qpow(Num base, u64 pow) {
    if (pow == 0) {
        return 1;
    } else if (pow == 1) {
        return base;
    }

    Num val = qpow(base, pow/2);
    if (pow % 2 == 0) {
        return val * val;
    } else {
        return val * val * base;
    }
}

int main() {
    u64 n;
    cin >> n;

    Matrix<Mod<1000000007>, 2, 2> mat = {{1,1},{1,0}};
    auto res = qpow(mat, n-1);

    cout << res[0][0] << endl;
    return 0;
}