#include <cstdint>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
using i64 = int64_t;

class shape {
public:
    const char color;
    explicit shape(char ch) : color(ch) {}
    virtual ~shape() {}

    virtual bool colored(i64 x, i64 y) const = 0;
};

class circle : public shape {
private:
    i64 cx, cy;
    i64 radius;
public:
    circle(char ch, i64 cx, i64 cy, i64 radius) : shape(ch), cx(cx), cy(cy), radius(radius) {}

    bool colored(i64 x, i64 y) const {
        i64 p = (x-cx)*(x-cx) + (y-cy)*(y-cy);
        return p <= radius * radius;
    }
};

class rectangle : public shape {
private:
    i64 x1, x2, y1, y2;
public:
    rectangle(char ch, i64 x1, i64 x2, i64 y1, i64 y2) : shape(ch), x1(x1), x2(x2), y1(y1), y2(y2) {}

    bool colored(i64 x, i64 y) const {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
};

void render(const vector<unique_ptr<shape>>& shapes, i64 x1, i64 x2, i64 y1, i64 y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (i64 y = y2; y >= y1; y--) {
        for (i64 x = x1; x <= x2; x++) {
            char ch = '.';
            for (auto it = shapes.rbegin(); it != shapes.rend(); it++) {
                auto& shape_ptr = *it;
                if (shape_ptr->colored(x, y)) {
                    ch = shape_ptr->color;
                    break;
                }
            }
            cout << ch;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<unique_ptr<shape>> shapes;
    shapes.reserve(n);
    for (int i=0; i<n; i++) {
        shape* ptr = nullptr;
        string cmd;
        cin >> cmd;
        if (cmd == "Circle") {
            i64 x, y, r;
            char col;
            cin >> x >> y >> r >> col;
            ptr = new circle(col, x, y, r);
        } else if (cmd == "Rectangle") {
            i64 x1, y1, x2, y2;
            char col;
            cin >> x1 >> y1 >> x2 >> y2 >> col;
            ptr = new rectangle(col, x1, x2, y1, y2);
        }
        if (ptr != nullptr) {
            shapes.emplace_back(ptr);
        } else {
            i64 x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            render(shapes, x1, x2, y1, y2);
        }
    }
    return 0;
}