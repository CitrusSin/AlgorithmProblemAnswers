#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int product = 1;
        for (int i=0; i<n; i++) {
            int k;
            cin >> k;
            if (k % 2 == 1) {
                product *= k;
            }
        }
        cout << product << endl;
    }
    return 0;
}