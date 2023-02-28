#include <stdio.h>

void itn(char *str, long long n, unsigned int radix) {
    if (n < 0) {
        *str = '-';
        str++;
        n = -n;
    }

    char *start = str;
    char *ptr = start;
    while (n > 0) {
        *ptr = (n % radix) + '0';
        if (*ptr > '9') {
            *ptr += 'A'-'9'-1;
        }
        n /= radix;
        ptr++;
    }

    *ptr = '\0';
    ptr--;
    while (start < ptr) {
        char swap = *start;
        *start = *ptr;
        *ptr = swap;
        start++;
        ptr--;
    }
}

long long nti(const char *str, unsigned int radix) {
    long long sign_mark = 1;
    if (*str == '-') {
        sign_mark = -1;
        str++;
    }

    long long result = 0;
    for (const char *ptr = str; *ptr; ptr++) {
        result *= radix;
        
        int digit = *ptr - '0';
        if (*ptr > '9') {
            digit -= 'A'-'9'-1;
        }
        result += digit;
    }

    return sign_mark * result;
}

int main() {
    long long n;
    unsigned int x;

    scanf("%lld%u", &n, &x);

    char ch[101];
    itn(ch, n, x);

    printf("%s\n", ch);

    return 0;
}