#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min_sticks = 0x7fffffff; // int max value
    int begin = (int)ceil(pow(n, 1/3.0));
    for (int a=begin; a<=n; a++) {
        for (int b=1; b<=a; b++) {
            for (int c=1; c<=b; c++) {
                if (a*b*c == n) {
                    int sticks = 2*(a*b+b*c+c*a);
                    if (sticks < min_sticks) {
                        min_sticks = sticks;
                    }
                }
            }
        }
    }

    cout << min_sticks << endl;
    return 0;
}