#include <iostream>
#include <vector>
#include <complex>
#include <assert.h>

using namespace std;

const double PI = 3.14159265358979323;

vector<complex<double>> fft_internal(const vector<complex<double>>& arr, int step, bool inv) {
    size_t n = 1<<step;
    vector<complex<double>> na(n);
    for (size_t i=0; i<n; i++) {
        size_t inv_bit = 0;
        for (int b=0; b<step; b++) {
            inv_bit <<= 1;
            inv_bit |= (bool)(i&(1<<(b)));
        }
        na[inv_bit] = arr[i];
    }

    for (size_t l=2; l<=n; l<<=1) {
        complex<double> omega = exp(complex<double>(0.0, (inv?-1:1)*2*PI/l));
        for (size_t i=0; i<n; i+=l) {
            complex<double> co = 1.0;
            for (size_t j=i; j<i+l/2; j++) {
                complex<double> a = na[j], b = co * na[j+l/2];
                na[j] = a+b;
                na[j+l/2] = a-b;
                co *= omega;
            }
        }
    }

    return na;
}

vector<complex<double>> fft(const vector<complex<double>>& arr) {
    int n = arr.size();
    assert((n&-n)==n);

    int step = -1;
    for (int n2 = n; n2; n2 >>= 1) step++;
    assert(step > 0);

    vector<complex<double>> res = fft_internal(arr, step, false);
    return res;
}

vector<complex<double>> ifft(const vector<complex<double>>& arr) {
    int n = arr.size();
    assert((n&-n)==n);

    int step = -1;
    for (int n2 = n; n2; n2 >>= 1) step++;
    assert(step > 0);

    vector<complex<double>> res = fft_internal(arr, step, true);
    for (complex<double>& num : res) {
        num /= n;
    }
    return res;
}

inline int integerize(double x) {
    int arr[3] = {(int)x, (int)x+1, (int)x+2};

    double min_diff = 100;
    int val = 0;
    for (int i=0; i<3; i++) {
        double diff = abs(x-arr[i]);
        if (diff < min_diff) {
            val = arr[i];
            min_diff = diff;
        }
    }
    
    return val;
}

template <typename StrIter>
string str_mul(StrIter b, StrIter e) {
    size_t total_size = 0;
    for (StrIter it = b; it != e; it++) {
        const string& str = *it;
        total_size += str.size();
    }
    size_t n = 1 << ((int)ceilf128(log2f128(total_size)));

    vector<complex<double>> fnum(n, complex<double>(1, 0));
    int cnt = 0;
    for (StrIter it = b; it != e; it++) {
        const string& str = *it;
        vector<complex<double>> num(n, complex<double>(0, 0));

        size_t sn = str.size();
        for (size_t i=0; i<sn; i++) {
            num[sn-i-1] = complex<double>(str[i]&0x0f, 0);
        }

        vector<complex<double>> res = fft(num);
        for (size_t i=0; i<n; i++) {
            fnum[i] *= res[i];
        }
        cnt++;
        if (cnt % 6 == 0) {
            vector<complex<double>> resd2 = ifft(fnum);
            vector<int> resi2(n);
            for (size_t i=0; i<n; i++) {
                resi2[i] = integerize(resd2[i].real());
            }
            size_t len = 1;
            for (size_t i=1; i<n; i++) {
                resi2[i] += resi2[i-1] / 10;
                resi2[i-1] %= 10;
                if (resi2[i]) len = i+1;
            }

            for (size_t i=0; i<n; i++) {
                fnum[i] = complex<double>(resi2[i], 0);
            }
            fnum = fft(fnum);
        }
    }

    vector<complex<double>> resd = ifft(fnum);
    vector<int> resi(n);
    for (size_t i=0; i<n; i++) {
        resi[i] = integerize(resd[i].real());
    }
    size_t len = 1;
    for (size_t i=1; i<n; i++) {
        resi[i] += resi[i-1] / 10;
        resi[i-1] %= 10;
        if (resi[i]) len = i+1;
    }
    
    string ress;
    while (len--) {
        ress.push_back(resi[len] + '0');
    }

    return ress;
}

string factorial(int n) {
    stringstream ss;
    for (int i=2; i<=n; i++) {
        ss << i << ' ';
    }
    vector<string> strs(n-1);
    for (int i=0; i<n-1; i++) {
        ss >> strs[i];
    }

    return str_mul(strs.begin(), strs.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << factorial(500) << endl;
    return 0;
}