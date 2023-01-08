#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) > 0) {
        double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        printf("%.2lf\n", dist);
    }
    return 0;
}