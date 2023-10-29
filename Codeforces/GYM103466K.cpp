#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

class Vec2 {
public:
    double x;
    double y;
    constexpr Vec2() : Vec2(0, 0) {}
    constexpr Vec2(double x, double y) : x(x), y(y) {}

    constexpr double squared_magnitude() const {
        return x*x + y*y;
    }

    double magnitude() const {
        return sqrt(squared_magnitude());
    }

    Vec2 normal() const {
        return (*this) / magnitude();
    }

    Vec2& normalize() {
        return *this /= magnitude();
    }

    Vec2& operator+=(const Vec2& v2) {
        x += v2.x;
        y += v2.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& v2) {
        x -= v2.x;
        y -= v2.y;
        return *this;
    }

    Vec2 operator+(const Vec2& v2) const {
        Vec2 v1 = *this;
        return v1 += v2;
    }

    Vec2 operator-(const Vec2& v2) const {
        Vec2 v1 = *this;
        return v1 -= v2;
    }

    Vec2 operator-() const {
        return Vec2(-x, -y);
    }

    Vec2& operator*=(double k) {
        x *= k;
        y *= k;
        return *this;
    }

    Vec2& operator/=(double k) {
        x /= k;
        y /= k;
        return *this;
    }

    Vec2 operator*(double k) const {
        Vec2 v1 = *this;
        return v1*=k;
    }

    Vec2 operator/(double k) const {
        Vec2 v1 = *this;
        return v1/=k;
    }
};

Vec2 operator*(double k, Vec2 v1) {
    return v1*=k;
}

double dot(const Vec2& v1, const Vec2& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double cross(const Vec2& v1, const Vec2& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

struct Line {
    Vec2 s;
    Vec2 t;

    Line() : s(), t() {}
    Line(const Vec2& s, const Vec2& t) : s(s), t(t) {}

    double len() const {
        return (t - s).magnitude();
    }

    Line reverse() const {
        return Line(t, s);
    }
};

double point_to_line(Vec2 p, Line l) {
    Vec2 s = l.s;
    Vec2 d = l.t - l.s;
    d.normalize();
    Vec2 r = p - s;
    return abs(cross(r, d));
}

bool at_line(Vec2 p, Line l) {
    return point_to_line(p, l) < 1e-6;
}

bool in_segment(Vec2 p, Line l) {
    Vec2 s = l.s;
    Vec2 d = l.t - l.s;
    d.normalize();
    Vec2 r = p - s;
    if (abs(cross(r, d)) > 1e-6) return false;
    double proj = dot(r, d);
    return proj >= 0 && proj <= l.len();
}


void solve() {
    int x1, y1, x2, y2, x3, y3, px, py;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> px >> py;

    Vec2 p1(x1, y1), p2(x2, y2), p3(x3, y3), p(px, py);

    array<Vec2, 3> vertices{p1, p2, p3};

    for (int i=0; i<3; i++) {
        if ((vertices[i]-p).magnitude() < 1e-6) {
            Vec2 rst;
            for (int j=0; j<3; j++) if (j != i) rst += vertices[j];
            rst /= 2;

            cout << rst.x << ' ' << rst.y << '\n';
            return;
        }
    }

    array<Line, 3> lines{Line(p1, p2), Line(p2, p3), Line(p3, p1)};
    int line = -1;
    for (int i=0; i<3; i++) {
        if (in_segment(p, lines[i])) {
            line = i;
            break;
        }
    }
    if (line == -1) {
        cout << -1 << '\n';
        return;
    }

    Line adj;
    if ((p - lines[line].s).squared_magnitude() < (p - lines[line].t).squared_magnitude()) {
        adj = lines[(line+1)%3];
    } else {
        adj = lines[(line+2)%3].reverse();
    }
    double h = point_to_line(p, adj);
    double sq = abs(cross(lines[0].t-lines[0].s, lines[1].t-lines[1].s)) / 2.0;
    double k = sq / h;
    Vec2 rst = adj.s + (adj.t - adj.s).normalize() * k;

    cout << rst.x << ' ' << rst.y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << std::setprecision(12);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}