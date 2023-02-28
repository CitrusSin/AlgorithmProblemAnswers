#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long int ull;

int main() {
    ull n;
    cin >> n;

    for (ull a=2; a<=n; a++) {
        for (ull b=2; b<a; b++) {
            for (ull c=b; c<a; c++) {
                for (ull d=c; d<a; d++) {
                    if (a*a*a == b*b*b+c*c*c+d*d*d) {
                        printf("Cube = %lu, Triple = (%lu,%lu,%lu)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}