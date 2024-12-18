#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <complex.h>
#include <assert.h>
#include <string.h>
#include <math.h>

const double PI = 3.14159265358979323;

void fft_internal(double complex *arr, int step, bool inv) {
    size_t n = 1 << step;
    for (size_t i=0; i<n; i++) {
        size_t bit_inv = 0;
        for (int k=0; k<step; k++) {
            bit_inv <<= 1;
            bit_inv |= (i&(1<<k))!=0;
        }
        if (i < bit_inv) {
            double complex sw = arr[i];
            arr[i] = arr[bit_inv];
            arr[bit_inv] = sw;
        }
    }

    for (size_t l=2; l<=n; l<<=1) {
        double complex omega = cexp((inv?-1:1)*2*PI/l*I);
        for (size_t i=0; i<n; i+=l) {
            double complex co = 1.0;
            for (size_t j=i; j<i+l/2; j++) {
                double complex a = arr[j], b = co * arr[j+l/2];
                arr[j] = a+b;
                arr[j+l/2] = a-b;
                co *= omega;
            }
        }
    }
}

void fft(double complex *arr, size_t n) {
    assert((n&-n) == n);
    int step = -1;
    while (n) {
        n >>= 1;
        step++;
    }
    fft_internal(arr, step, false);
}

void ifft(double complex *arr, size_t n) {
    assert((n&-n) == n);
    int step = -1;
    size_t n2 = n;
    while (n2) {
        n2 >>= 1;
        step++;
    }
    fft_internal(arr, step, true);
    for (size_t i=0; i<n; i++) arr[i] /= (double)n;
}

static inline int integerize(double x) {
    int vals[3] = {(int)x, (int)x+1, (int)x+2};
    int r = 0;
    double err = 2;
    for (int i=0; i<3; i++) {
        double e2 = fabs(x-vals[i]);
        if (e2 < err) {
            err = e2;
            r = vals[i];
        }
    }
    return r;
}

size_t str_mul_sized(char* product, const char* a, size_t na, const char* b, size_t nb) {
    size_t n = 1 << ((int)ceil(log2(na+nb)));

    double complex ca[n], cb[n];

    memset(ca, 0, sizeof(ca));
    memset(cb, 0, sizeof(cb));

    for (size_t i=0; i<na; i++) {
        ca[na-i-1] = (double complex)(a[i] - '0');
    }
    for (size_t i=0; i<nb; i++) {
        cb[nb-i-1] = (double complex)(b[i] - '0');
    }

    fft(ca, n);
    fft(cb, n);
    for (size_t i=0; i<n; i++) ca[i] *= cb[i];
    ifft(ca, n);

    int resi[n];
    for (size_t i=0; i<n; i++) {
        resi[i] = integerize(creal(ca[i]));
    }

    size_t maxi = 1;
    for (size_t i=1; i<n; i++) {
        resi[i] += resi[i-1]/10;
        resi[i-1] %= 10;
        if (resi[i]) maxi = i+1;
    }

    size_t len = maxi;
    while (maxi--) {
        *product++ = resi[maxi] + '0';
    }
    *product = '\0';
    return len;
}

size_t reads(char* str, size_t max_size) {
    size_t read_size = 0;
    int c = getchar();
    while (c <= 0x20 || c > 0x7E) {
        c = getchar();
    }
    while (read_size < max_size-1) {
        if (c > 0x20 && c <= 0x7E) {
            *str++ = c;
            read_size++;
            c = getchar();
        } else break;
    }
    *str = '\0';
    return read_size;
}

char product[2000002], a[1000002], b[1000002];

int main() {
    size_t na = reads(a, sizeof(a)), nb = reads(b, sizeof(b));
    size_t s = str_mul_sized(product, a, na, b, nb);
    fwrite(product, s, 1, stdout);
    putchar('\n');
    return 0;
}
