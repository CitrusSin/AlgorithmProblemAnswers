#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool solve(int n, int m) {
    return 2*m+1 <= (int)sqrt(8*n+1);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i=0; i<t; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (solve(n, m)) {
            printf("possible\n");
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}