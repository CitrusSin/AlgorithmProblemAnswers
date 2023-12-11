#include <iostream>

using namespace std;

int main() {
    int k, g, m;
    cin >> k >> g >> m;
    
    int a = 0, b = 0;
    for (int i=0; i<k; i++) {
        if (a == g) {
            a = 0;
        } else if (b == 0) {
            b = m;
        } else {
            int trs = min(b, g-a);
            a += trs;
            b -= trs;
        }
    }

    cout << a << ' ' << b << endl;
    return 0;
}