#include <iostream>
#include <cstdio>

using namespace std;

#define PI 3.1415926
#define DELTA 1e-4

bool check_pie_available(double *volumes, int n, int f, double pp) {
    int tp = 0;
    for (int i=0; i<n; i++) {
        tp += (int)(volumes[i]/pp);
        if (tp >= f) {
            return true;
        }
    }
    return tp >= f;
}

int main() {
    int n, f;
    cin >> n >> f;
    f++;

    double volumes[n];
    double total_vol = 0;
    for (int i=0; i<n; i++) {
        double radius;
        cin >> radius;

        double vol = PI * radius * radius;
        volumes[i] = vol;
        total_vol += vol;
    }

    double l = 0., h = total_vol/(double)f;
    while (h-l>=DELTA) {
        double mid = (l+h)/2.;
        if (check_pie_available(volumes, n, f, mid)) {
            l = mid;
        } else {
            h = mid;
        }
    }
    printf("%.3lf\n", l);
    return 0;
}