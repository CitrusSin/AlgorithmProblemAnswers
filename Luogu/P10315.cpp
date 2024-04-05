#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

int64_t mod = 3;

int64_t qpow(int64_t base, uint64_t exp) {
    int64_t r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r % mod;
        r = r * r % mod;
        exp >>= 1;
    }
    return rst;
}

int64_t inv(int64_t x) {
    return qpow(x, mod - 2);
}

class matrix {
private:
    size_t n, m;
    //vector<vector<int64_t>> values;
    int64_t *data;
public:
    matrix(size_t n, size_t m) : n(n), m(m) {
        //values.assign(n, vector<int64_t>(m, 0));
        data = new int64_t[n * m];
        for (size_t i=0; i<n; i++) {
            for (size_t j=0; j<m; j++) {
                (*this)(i, j) = 0;
            }
        }
    }

    matrix(const matrix& mat2) : n(mat2.n), m(mat2.m) {
        data = new int64_t[mat2.n * mat2.m];
        for (size_t i=0; i<mat2.n*mat2.m; i++) {
            data[i] = mat2.data[i];
        }
    }

    matrix(matrix&& mat2) : n(mat2.n), m(mat2.m) {
        data = mat2.data;
        mat2.data = nullptr;
    }

    ~matrix() {
        if (data != nullptr) delete[] data;
    }

    const int64_t& operator()(size_t i, size_t j) const {
        return data[i * m + j];
    }

    int64_t& operator()(size_t i, size_t j) {
        return data[i * m + j];
    }

    int64_t& operator()(size_t i) {
        assert(m == 1 || n == 1);
        return data[i];
    }

    matrix operator+(const matrix& m2) const {
        assert(n == m2.n && m == m2.m);
        matrix ans(n, m);
        const matrix &m1 = *this;
        for (size_t i=0; i<n; i++) {
            for (size_t j=0; j<m; j++) {
                ans(i, j) = (m1(i, j) + m2(i, j)) % mod;
            }
        }
        return ans;
    }

    matrix operator-(const matrix& m2) const {
        assert(n == m2.n && m == m2.m);
        matrix ans(n, m);
        const matrix &m1 = *this;
        for (size_t i=0; i<n; i++) {
            for (size_t j=0; j<m; j++) {
                ans(i, j) = (mod + m1(i, j) - m2(i, j)) % mod;
            }
        }
        return ans;
    }

    matrix operator*(const matrix& m2) const {
        const matrix& m1 = *this;

        assert(m1.m == m2.n);
        size_t n = m1.n, m = m2.m, k = m1.m;

        matrix m3(n, m);
        for (size_t i=0; i<n; i++) {
            for (size_t j=0; j<m; j++) {
                for (size_t u=0; u<k; u++) {
                    m3(i, j) += m1(i, u) * m2(u, j) % mod;
                    m3(i, j) %= mod;
                }
            }
        }
        return m3;
    }

    void swap_rows(size_t i, size_t j) {
        matrix& self = *this;
        for (size_t k=0; k<m; k++) {
            swap(self(i, k), self(j, k));
        }
    }

    matrix inverse() const {
        assert(this->n == this->m);

        size_t n = this->n;
        matrix m = *this, sc(n, n);
        
        for (size_t i=0; i<n; i++) {
            sc(i, i) = 1;
        }
        // Upper triangle
        for (size_t i=0; i<n; i++) {
            if (m(i, i) == 0) {
                size_t j = i + 1;
                while (j < n && m(j, i) == 0) j++;
                if (j == n) {
                    // 
                    throw runtime_error("Arimethic error");
                }
                m.swap_rows(i, j);
                sc.swap_rows(i, j);
            }

            int64_t p = inv(m(i, i));
            for (size_t j=0; j<n; j++) {
                m(i, j) = m(i, j) * p % mod;
                sc(i, j) = sc(i, j) * p % mod;
            }

            for (size_t j=i+1; j<n; j++) {
                int64_t p2 = m(j, i);
                if (p2 == 0) continue;
                for (size_t k=0; k<n; k++) {
                    m(j, k) = (mod + m(j, k) - p2 * m(i, k) % mod) % mod;
                    sc(j, k) = (mod + sc(j, k) - p2 * sc(i, k) % mod) % mod;
                }
            }
        }
        // 
        for (size_t i=n-1; i<n; i--) {
            for (size_t j=i-1; j<n; j--) {
                int64_t p = m(j, i);
                if (p == 0) continue;
                for (size_t k=0; k<n; k++) {
                    m(j, k) = (mod + m(j, k) - p * m(i, k) % mod) % mod;
                    sc(j, k) = (mod + sc(j, k) - p * sc(i, k) % mod) % mod;
                }
            }
        }

        return sc;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> mod;

    matrix co(n, n);

    for (int i=0; i<n; i++) {
        co(i, i) = 1;
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            a--;
            co(a, i) = 1;
        }
    }

    matrix s(n, 1), t(n, 1);
    for (int i=0; i<n; i++) cin >> s(i);
    for (int i=0; i<n; i++) cin >> t(i);

    try {
        matrix m2 = co.inverse();
        matrix c = m2 * (t - s);

        for (int i=0; i<n; i++) {
            if (i) cout << ' ';
            cout << c(i);
        }
        cout << '\n';
    } catch (runtime_error re) {
        cout << "niuza\n";
    }

    return 0;
}
