#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    char data[4];
    while (scanf("%3s", data) > 0) {
        sort(data, data+3);
        for (int i=0; i<3; i++) {
            cout << data[i];
            if (i == 2) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}