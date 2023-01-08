#include <bits/stdc++.h>
using namespace std;

const double exc = 1e-6;

constexpr double calc_poly(double x, double a, double b, double c, double d) {
    return a*x*x*x+b*x*x+c*x+d;
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    // 二分查找其中一个根（一定能找到）
    double l = -101.0, r = 101.0;
    double lval = calc_poly(l, a, b, c, d), rval = calc_poly(r, a, b, c, d);
    while (abs(l-r) > exc) {
        double mid = (l+r)/2;
        double val = calc_poly(mid, a, b, c, d);
        if (val * lval < 0) {
            r = mid;
            rval = val;
        } else {
            l = mid;
            lval = val;
        }
    }

    // 因式分解为二次方程求得剩余两解
    double e = l;
    
    double f = a;
    double g = b+a*e;
    double h = c+a*e*e+b*e;

    a = f;
    b = g;
    c = h;

    double sqdelta = sqrt(b*b-4*a*c);
    f = (-b+sqdelta)/(2*a);
    g = (-b-sqdelta)/(2*a);

    double solves[3] = {e, f, g};
    sort(solves, solves+3);

    printf("%.2lf %.2lf %.2lf\n", solves[0], solves[1], solves[2]);
    return 0;
}