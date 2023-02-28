#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;

    int counter = 0;
    while (m > n) {
        if (m % 2 == 1) {
            m++;
        } else {
            m /= 2;
        }
        counter++;
    }
    counter += n-m;

    if (counter < 100) {
        cout << "WIN " << counter << endl;
    } else if (counter >= 100 && counter <= 300) {
        cout << "DEFEAT " << counter << endl;
    } else {
        cout << "DevilG was beaten!" << endl;
    }
    return 0;
}