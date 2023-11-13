#include <iostream>

using namespace std;

bool judge(int x, int y) {
    if (x > y) {
        return x-y<=3;
    } else {
        return y-x<=2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    cout << (judge(x, y)?"Yes":"No") << endl;
    return 0;
}