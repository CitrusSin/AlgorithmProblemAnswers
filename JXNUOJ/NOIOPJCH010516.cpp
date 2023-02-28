#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    double price = 200, money = n;
    double rate = 1.0 + k/100.0;

    for (int year = 1; year <= 20; year++) {
        if (price <= money) {
            cout << year << endl;
            return 0;
        }
        price *= rate;
        money += n;
    }
    cout << "Impossible" << endl;
    return 0;
}