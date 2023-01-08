#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    while (scanf("%lf", &x) > 0) {
        printf("%.2lf\n", fabs(x));
    }
    return 0;
}