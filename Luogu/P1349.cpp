#include <bits/stdc++.h>

using namespace std;

template <typename T>
T qpow(const T& base, uint64_t exp) {
    T r(base), rst(1);
    while (exp) {
        if (exp & 1) rst = rst * r;
        r = r * r;
        exp >>= 1;
    }
    return rst;
}

template <uint64_t Mod>
class GF {
private:
    uint64_t value;
public:
    GF() : value() {}
    GF(uint64_t value) : value(value % Mod) {}

    operator uint64_t() const {
        return value;
    }

    GF<Mod> inv() const {
        return qpow<GF<Mod>>(*this, Mod-2);
    }

    GF<Mod> operator+(const GF<Mod>& v2) const {
        return GF<Mod>(value + v2.value);
    }

    GF<Mod> operator-(const GF<Mod>& v2) const {
        return GF<Mod>(Mod + value - v2.value);
    }

    GF<Mod> operator-() const {
        return GF<Mod>(Mod - value);
    }

    GF<Mod> operator*(const GF<Mod>& v2) const {
        return GF<Mod>(value * v2.value);
    }

    GF<Mod> operator/(const GF<Mod>& v2) const {
        return this->operator*(v2.inv());
    }    
};

template <typename Num, size_t Mod>
GF<Mod> operator+(Num v1, const GF<Mod>& v2) {
    return GF<Mod>(v1) + v2;
}
template <typename Num, size_t Mod>
GF<Mod> operator-(Num v1, const GF<Mod>& v2) {
    return GF<Mod>(v1) - v2;
}
template <typename Num, size_t Mod>
GF<Mod> operator*(Num v1, const GF<Mod>& v2) {
    return GF<Mod>(v1) * v2;
}
template <typename Num, size_t Mod>
GF<Mod> operator/(Num v1, const GF<Mod>& v2) {
    return GF<Mod>(v1) / v2;
}

class DynGF {
private:
    uint64_t value, mod;
public:
    DynGF(uint64_t value, uint64_t mod) : value(value % mod), mod(mod) {}
    DynGF(uint64_t mod) : mod(mod) {}


};

template <typename T, size_t N, size_t M>
class Matrix {
private:
    array<array<T, M>, N> data;

    Matrix(array<array<T, M>, N>&& d) : data(d) {}
public:
    class RowReference;
    class ConstRowReference; 

    Matrix() : data() {}
    Matrix(T val) : data() {
        for (size_t i=0; i<min(N, M); i++) {
            data[i][i] = val;
        }
    }

    ConstRowReference operator[](size_t index) const {
        return ConstRowReference(&data, index);
    }

    RowReference operator[](size_t index) {
        return RowReference(&data, index);
    }

    template <size_t K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& mat2) {
        Matrix<T, N, K> ans;
        for (size_t i=0; i<N; i++) {
            for (size_t j=0; j<K; j++) {
                ans.data[i][j] = 0;
                for (size_t k=0; k<M; k++) {
                    ans.data[i][j] = ans.data[i][j] + data[i][k] * mat2.data[k][j];
                }
            }
        }
        return ans;
    }
    
    class RowReference {
    private:
        array<array<T, M>, N> *pointer;
        size_t row_count;
        RowReference(array<array<T, M>, N> *pointer, size_t rc) : pointer(pointer), row_count(rc) {}

        friend class Matrix<T, N, M>;
    public:
        RowReference() = delete;
        RowReference(RowReference&& r) = delete;
        RowReference(const RowReference& r) = delete;
        
        RowReference& operator=(RowReference&& r2) = delete;
        RowReference& operator=(const RowReference& r2) = delete;

        T& operator[](size_t index) {
            return (*pointer)[row_count][index];
        }
    };

    class ConstRowReference {
    private:
        const array<array<T, M>, N> *pointer;
        size_t row_count; 
        ConstRowReference(const array<array<T, M>, N> *pointer, size_t rc) : pointer(pointer), row_count(rc) {}
        friend class Matrix<T, N, M>;
    public:
        ConstRowReference() = delete;
        ConstRowReference(ConstRowReference&& r) = delete;
        ConstRowReference(const ConstRowReference& r) = delete;
        
        ConstRowReference& operator=(ConstRowReference&& r2) = delete;
        ConstRowReference& operator=(const ConstRowReference& r2) = delete;

        const T& operator[](size_t index) {
            return (*pointer)[row_count][index];
        }
    };
};

using GFM = GF<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    uint64_t pt, qt, a1t, a2t, nt, mt;
    cin >> pt >> qt >> a1t >> a2t >> nt >> mt;

    

    return 0;
}