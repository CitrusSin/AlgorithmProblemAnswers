#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int bti(const char* str) {
    int result = 0;
    for (const char* ptr = str; *ptr; ptr++) {
        if (*ptr == '0' || *ptr == '1') {
            result *= 2;
        } else {
            break;
        }
        if (*ptr == '1') {
            result += 1;
        }
    }
    return result;
}

void itb(char *str, int val) {
    if (val == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    char *ptr = str;
    while (val > 0) {
        int r = val%2;
        if (r) {
            *ptr = '1';
        } else {
            *ptr = '0';
        }
        val /= 2;
        ptr++;
    }
    *ptr = '\0';

    // Reverse
    int len = strlen(str);
    for (int i=0; i<len/2; i++) {
        int swap = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = swap;
    }
}

int main() {
    char a[20], b[20];
    scanf("%s %s", a, b);
    int ia = bti(a), ib = bti(b);
    
    int ic = ia+ib;
    char c[21];
    itb(c, ic);
    printf("%s\n", c);
    return 0;
}