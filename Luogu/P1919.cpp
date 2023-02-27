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

string smul(const string& a, const string& b) {
    size_t n = 1 << ((int)ceilf128(log2f128(a.size() + b.size())));

    vector<complex<double>> ax(n, 0), bx(n, 0);
    size_t sa = a.size(), sb = b.size();
    for (size_t i=0; i<sa; i++) {
        ax[sa-i-1] = complex<double>(a[i]&0x0f, 0);
    }
    for (size_t i=0; i<sb; i++) {
        bx[sb-i-1] = complex<double>(b[i]&0x0f, 0);
    }

    vector<complex<double>> fax = fft(ax), fbx = fft(bx);
    for (size_t i=0; i<n; i++) fax[i] *= fbx[i];
    vector<complex<double>> resd = ifft(fax);
    vector<int> resi(n);
    for (size_t i=0; i<n; i++) {
        resi[i] = integerize(resd[i].real());
    }
    size_t len = 1;
    for (size_t i=1; i<n; i++) {
        resi[i] += resi[i-1]/10;
        resi[i-1] %= 10;
        if (resi[i]) len = i+1;
    }
    
    string ress;
    while (len--) {
        ress.push_back(resi[len] + '0');
    }

    return ress;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    cout << smul(a, b) << endl;
    return 0;
}