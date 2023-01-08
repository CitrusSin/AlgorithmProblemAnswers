#include <stdio.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>

float q_sqrt(float x) {
    union {
        float f;
        int32_t i;
    } conv;
    conv.f = x;
    conv.i = (conv.i>>1) + 0x1fbbd8ae;
    float base = conv.f;

    base = base/2.f + x/(2.f*base);
    base = base/2.f + x/(2.f*base);
    return base;
}

double q_sqrtd(double x) {
    union {
        double d;
        int64_t i;
    } conv;
    conv.d = x;
    conv.i = (conv.i>>1) + 0x1ff77b15b573eab3;
    double base = conv.d;

    base = base/2. + x/(2.*base);
    base = base/2. + x/(2.*base);

    return base;
}

int main() {
    while (1) {
        double d;
        scanf("%lf", &d);
        printf("sqrt: %lf\n", sqrt(d));
        printf("q_sqrtd: %lf\n", q_sqrtd(d));
    }
    
    return 0;
}