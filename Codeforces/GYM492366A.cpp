#include <iostream>

using namespace std;

int region(int x, int y) {
    int a = x < 0;
    int b = y < 0;
    return (a << 1) | b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << (region(x1, y1) != region(x2, y2)) << endl;
    return 0;
}