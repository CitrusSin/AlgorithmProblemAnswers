#include <bits/stdc++.h>
using namespace std;

int reg[11][11];
int calculate(int a, int b) {
    if (a > b) return reg[b-1][a-1];
    double da = a, db = b;
    int sq = max(a, b);
    double total = 0;
    constexpr double step = 1e-2;
    for (double x=-sq; x<=sq; x+=step) {
        for (double y=-sq; y<=sq; y+=step) {
            bool cond = true;
            cond &= (x*x)/(da*da) + (y*y)/(db*db) <= 1;
            if (cond) cond &= (x*x)/(db*db) + (y*y)/(da*da) <= 1;
            if (cond) cond &= x*x+y*y+x*y<=a;
            if (cond) cond &= x*x+y*y-x*y<=b;

            if (cond) {
                total += step*step;
            }
        }
    }
    int result = (int)floor(total);
    reg[a-1][b-1] = result;
    return result;
}

int main() {
    cout << "{";
    for (int a=1; a<=10; a++) {
        cout << "{";
        for (int b=1; b<=10; b++) {
            cout << calculate(a, b) << ",";
        }
        cout << "}," << endl;
    }
    cout << "}";
    return 0;
}