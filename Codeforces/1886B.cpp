#include <bits/stdc++.h>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(double(x1-x2)*(x1-x2) + double(y1-y2)*(y1-y2));
}

void solve() {
    int px, py;
    cin >> px >> py;
    int ax, ay;
    cin >> ax >> ay;
    int bx, by;
    cin >> bx >> by;

    double distc = dist(ax, ay, bx, by) / 2.0;
    double dist1 = dist(px, py, ax, ay);
    double dist2 = dist(px, py, bx, by);
    double dist3 = dist(0, 0, ax, ay);
    double dist4 = dist(0, 0, bx, by);

    double w = max(min(dist3, dist4), min(dist1, dist2));
    if (w < dist2 && w < dist3 || w < dist1 && w < dist4) {
        w = max(w, distc);
    }
    
    cout << w << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(8);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}