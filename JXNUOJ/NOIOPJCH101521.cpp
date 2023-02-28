#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull n;
    cin >> n;

    while (n != 0 && n != 1) {
        if (n%2==1) {
            ull result = n*3+1;
            cout << n << "*3+1=" << result << endl;
            n = result;
        } else {
            ull result = n/2;
            cout << n << "/2=" << result << endl;
            n = result;
        }
    }
    cout << "End" << endl;
    return 0;
}