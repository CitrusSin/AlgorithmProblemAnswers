#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        int sum1=0, sum2=0;
        for (int i=x; i<=y; i++) {
            if (i % 2 == 0) {
                sum1 += i*i;
            } else {
                sum2 += i*i*i;
            }
        }
        cout << sum1 << " " << sum2 << endl;
    }
    return 0;
}