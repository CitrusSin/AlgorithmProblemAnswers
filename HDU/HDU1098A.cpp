#pragma GCC optimize("O2")
#pragma G++ optimize("O2")
#include <bits/stdc++.h>

using namespace std;

struct Vec2 {
    const double x;
    const double y;
    const double mag;

    Vec2() : x(0), y(0), mag(0) {}
    Vec2(double x, double y) : x(x), y(y), mag(sqrt(x*x + y*y)) {}

    double squared_magnitude() const {
        return x*x + y*y;
    }
    double magnitude() const {
        return mag;
    }
    Vec2 normalize() const {
        double mag = magnitude();
        return Vec2(x/mag, y/mag);
    }

    Vec2 operator+(const Vec2& v2) const {
        return Vec2(x+v2.x, y+v2.y);
    }
    Vec2 operator-(const Vec2& v2) const {
        return Vec2(x-v2.x, y-v2.y);
    }
    Vec2 operator*(double ratio) const {
        return Vec2(x * ratio, y * ratio);
    }
    Vec2 operator/(double ratio) const {
        return operator*(1.0/ratio);
    }
    double operator*(const Vec2& v2) const {
        return x * v2.x + y * v2.y;
    }
};

class Line {
    Vec2 point_a;
    Vec2 point_b;

    mutable optional<double> len;

public:
    Line() : point_a(), point_b() {}
    Line(Vec2 pa, Vec2 pb) : point_a(pa), point_b(pb) {}

    double length() const {
        if (!len.has_value()) len = (point_a - point_b).magnitude();
        return len.value();
    }

    double distance_to(const Vec2& point) const {
        Vec2 line = (point_b - point_a) / length();
        double proj = line * (point - point_a);
        if (proj >= 0 && proj <= length()) {
            Vec2 spot = point_a + line * proj;
            return (point - spot).magnitude();
        } else if (proj <= 0) {
            return (point - point_a).magnitude();
        } else {
            return (point - point_b).magnitude();
        }
    }
};

int qread() {
    char c = getchar();
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
    bool neg = c == '-';
    if (neg) c = getchar();
    int rst = 0;
    while (c >= '0' && c <= '9') {
        rst *= 10;
        rst += c & 0x0f;
        c = getchar();
    }
    return (neg?-1:1)*rst;
}

int main() {
    cout << fixed << setprecision(4);

    int m, n;
    m = qread();
    n = qread();

    vector<Vec2> points;
    points.reserve(m);
    for (int i=0; i<m; i++) {
        //cin >> points[i].x >> points[i].y;
        int x = qread();
        int y = qread();
        points.emplace_back(x, y);
        if (points.size() >= 2 && (points[points.size()-1] - points[points.size()-2]).magnitude() < 0.5) {
            points.pop_back();
        }
    }
    m = points.size();

    if (m == 1) {
        Vec2 ref = points[0];
        for (int r=0; r<n; r++) {
            int sx = qread();
            int sy = qread();
            Vec2 shelter(sx, sy);

            cout << (shelter - ref).magnitude() << '\n';
        }
        return 0;
    }

    vector<Line> track;
    track.reserve(m-1);
    for (int i=0; i<m-1; i++) {
        track.emplace_back(points[i], points[i+1]);
    }

    for (int r=0; r<n; r++) {
        int sx = qread();
        int sy = qread();
        Vec2 shelter(sx, sy);

        double min_dist = numeric_limits<double>::max();
        for (int i=0; i<m-1; i++) {
            min_dist = min(min_dist, track[i].distance_to(shelter));
        }
        cout << min_dist << '\n';
    }
    return 0;
}