#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159

int main() {
    double radius;
    while (scanf("%lf", &radius) == 1) {
        printf("%.3lf\n", 4*PI*radius*radius*radius/3.0);
    }
    return 0;
}