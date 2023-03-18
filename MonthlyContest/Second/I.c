#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char s[200001];

int main() {
    int n, c, q;
    scanf("%d%d%d\n", &n, &c, &q);
    fgets(s, 200001, stdin);
    
    for (int i=0; i<c; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int l2 = r-l+1;
        memcpy(s+n, s+l-1, l2);
        n+=l2;
    }

    for (int i=0; i<q; i++) {
        int t;
        scanf("%d", &t);
        putchar(s[t-1]);
        putchar('\n');
    }
    return 0;
}