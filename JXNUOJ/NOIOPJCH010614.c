#include <stdio.h>
#include <memory.h>

#define MAX_LEN 100000

int main() {
    int n, fclen=0;
    char fc[MAX_LEN] = {0}, f2[MAX_LEN] = {0};

    scanf("%d", &n);

    fc[0] = 1;
    fclen++;
    for (int i=2; i<=n; i++) {
        memcpy(f2, fc, fclen);
        memset(fc, 0, fclen);
        // fc mul i
        int bshift = 0;
        int max_l = fclen;
        for (int j=i; j>0; j/=10) {
            // for every bit of i
            int b = j%10;
            int fw = 0;
            for (int k=0; k<fclen; k++) {
                fc[k+bshift] += f2[k]*b + fw;
                fw = fc[k+bshift]/10;
                fc[k+bshift] %= 10;
                
                if (k+bshift >= max_l) max_l = k+bshift+1;
            }
            if (fw) {
                fc[fclen+bshift] += fw;
                max_l++;
            }
            bshift++;
        }
        fclen = max_l;
    }

    for (int i=fclen-1; i>=0; i--) {
        putchar(fc[i] | 0x30);
    }
    putchar('\n');
    return 0;
}