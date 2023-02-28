#include <bits/stdc++.h>
using namespace std;

struct rect {
    int x1;
    int y1;
    int x2;
    int y2;
    int square() {
        return abs(x2-x1)*abs(y2-y1);
    };
};

rect read_rect(istream& is) {
    rect r;
    is >> r.x1 >> r.y1  >> r.x2 >> r.y2;
    return r;
}

int overlap_len(int a1, int a2, int b1, int b2) {
    int al = min(a1, a2), ar = max(a1, a2);
    int bl = min(b1, b2), br = max(b1, b2);
    return max(0, min(ar, br)-max(al, bl));
}

int overlap_area(const rect& r1, const rect &r2) {
    int xlap = overlap_len(r1.x1, r1.x2, r2.x1, r2.x2);
    int ylap = overlap_len(r1.y1, r1.y2, r2.y1, r2.y2);
    return xlap * ylap;
}

int main() {
    rect r1 = read_rect(cin), r2 = read_rect(cin), r3 = read_rect(cin);
    int s1 = r1.square(), s2 = r2.square();
    int p1 = overlap_area(r1, r3), p2 = overlap_area(r2, r3);
    cout << s1+s2-p1-p2 << endl;
    return 0;
}