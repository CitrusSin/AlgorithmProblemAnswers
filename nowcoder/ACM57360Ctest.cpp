#include <iostream>

using namespace std;

int main() {
    for (int i=0; i<100; i++) {
        int val;
        if (i % 2 == 0) {
            val = i/10;
        } else {
            val = (i+5)/10;
        }
        cout << i << ' ' << val << endl;
    }
}