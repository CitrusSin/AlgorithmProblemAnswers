#include <stdio.h>

typedef unsigned long long ull;

ull matrix_value(ull n, ull x, ull y) {
    if (x == 0 && y > 0) {
        return y*(y+1)/2;
    } else if (y == n-1) {
        return matrix_value(n, 0, y) + (n*x - x*(x-1)/2);
    } else if (x+y>=n) {
        return matrix_value(n, (x+y)-(n-1), n-1) + (n-1-y);
    } else {
        return matrix_value(n, 0, x+y) + x;
    }
}

int main() {
    ull n, x, y;
    scanf("%llu%llu%llu", &n, &x, &y);
    printf("%llu\n", matrix_value(n, x, y));
    return 0;
}