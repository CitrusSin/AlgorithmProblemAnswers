#include <bits/stdc++.h>

using namespace std;

struct figure {
    int r;
    int c;
    int h;
    int w;
    figure(int r, int c, int h, int w) : r(r), c(c), h(h), w(w) {}
    figure() : figure(0, 0, 0, 0) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;
    x--, y--;

    bool flipped = false;
    if (x > y) {
        flipped = true;
        swap(x, y);
    }

    vector<figure> fgs;
    for (int i=1; i<=x; i++) {
        fgs.emplace_back(x-i, y-i, i, i);
    }
    int dif = y-x;
    int len = x+1;
    for (int i=1; i<=dif; i++) {
        fgs.emplace_back(x+i, dif-i, -len, len);
        len++;
    }
    for (int i=len; i<n; i++) {
        fgs.emplace_back(i, i, -i, -i);
    }

    if (flipped) {
        for (figure& f : fgs) {
            swap(f.r, f.c);
            swap(f.h, f.w);
        }
    }

    cout << "Yes" << endl;
    cout << fgs.size() << endl;
    for (figure& f : fgs) {
        cout << (f.r+1) << ' ' << (f.c+1) << ' ' << f.h << ' ' << f.w << endl;
    }
    return 0;
}