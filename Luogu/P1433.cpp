#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

double distance(const Point &p1, const Point &p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx+dy*dy);
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i=0; i<n; i++) {
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }
    
    double dp[n][1<<n];
    for (int s=0; s<(1<<n); s++) {
        for (int i=0; i<n; i++) {
            if (s == (1 << i)) {
                dp[i][s] = sqrt(points[i].x*points[i].x+points[i].y*points[i].y);
            } else if (s & (1 << i)) {
                double min_distance = 4000;
                int s2 = s & ~(1<<i);
                for (int i2=0; i2<n; i2++) {
                    if ((1<<i2)&s2) {
                        min_distance = min(min_distance, dp[i2][s2] + distance(points[i], points[i2]));
                    }
                }
                dp[i][s] = min_distance;
            }
        }
    }

    double result = dp[0][(1<<n)-1];
    for (int i=0; i<n; i++) {
        result = min(result, dp[i][(1<<n)-1]);
    }
    printf("%.2lf\n", result);
    return 0;
}