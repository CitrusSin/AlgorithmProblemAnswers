#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

double ppow(double base, int exp) {
    double rst = 1.0;
    for (int i=0; i<exp; i++) {
        rst *= base;
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(4);

    int k, t;
    double p;
    cin >> k >> t >> p;

    double sp = 1.0 - ppow(1.0-p, t);
    sp *= k;
    cout << sp << endl;
    return 0;
}