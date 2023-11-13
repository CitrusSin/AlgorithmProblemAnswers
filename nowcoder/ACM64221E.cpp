#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238;

struct Vec2 {
    double x;
    double y;
    Vec2(double x=0, double y=0) : x(x), y(y) {}
    Vec2 rotate(double rad) const {
        return Vec2(x*cos(rad)-y*sin(rad), x*sin(rad)+y*cos(rad));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(2);

    int n;
    cin >> n;

    double l = (cos(2*PI/5.0)+1)*(double)n / cos(PI/10.0);
    array<Vec2, 5> vecs;
    for (int i=0; i<5; i++) {
        vecs[i] = Vec2(l, 0).rotate(PI/10.0 + i*2*PI/5.0);
    }

    double delta = l * sin(PI/10.0);

    if (n == 0) {
        vecs.fill(Vec2(0, 0));
    }

    char c = 'A';
    for (int i=5; i>=1; i--) {
        int idx = i % 5;
        cout << (c++) << ": " << vecs[idx].x << ' ' << (vecs[idx].y - delta) << endl;
    }

    return 0;
}