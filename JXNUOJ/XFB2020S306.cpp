#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;

    int h = (n+1)/2;
    for (int y=0; y<h; y++) {
        for (int x=0; x<n; x++) {
            if (abs(y-n/2)+abs(x-n/2) <= n/2) {
                putchar('*');
            } else {
                if (x<=n-(h-y)) putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}