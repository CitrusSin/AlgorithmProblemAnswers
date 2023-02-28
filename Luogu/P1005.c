#include <stdio.h>

typedef unsigned __int128 num;

num max(num a, num b) {
    return a>b?a:b;
}

num maximum_score(const num *arr, int n) {
    num scores[n+1][n+1];
    scores[0][n] = 0;
    for (int n2 = n-1; n2 >= 0; n2--) {
        for (int begin = 0; begin <= n-n2; begin++) {
            int end = begin + n2;
            num sc = 0;
            if (begin >= 1) {
                sc = max(sc, scores[begin-1][end] + (arr[begin-1] * (((num)1) << (n-n2))));
            }
            if (end <= n-1) {
                sc = max(sc, scores[begin][end+1] + (arr[end] * (((num)1) << (n-n2))));
            }
            scores[begin][end] = sc;
        }
    }
    num max_result = 0;
    for (int i=0; i<=n; i++) {
        if (scores[i][i] > max_result) {
            max_result = scores[i][i];
        }
    }
    return max_result;
}

num read_num() {
    num result = 0;
    char c = '\0';
    while (!(c>='0'&&c<='9')) {
        c = getchar();
    }
    while (c>='0'&&c<='9') {
        result *= 10;
        result += c & 0x0f;
        c = getchar();
    }
    return result;
}

void print_num(num n) {
    if (n != 0) {
        char str[43] = {'\0'};
        char *str_p = str;
        while (n > 0) {
            *str_p = (n % 10) | 0x30;
            n /= 10;
            str_p++;
        }
        str_p--;

        char *str_pb = str;
        while (str_pb < str_p) {
            char swap = *str_pb;
            *str_pb = *str_p;
            *str_p = swap;

            str_pb++;
            str_p--;
        }

        printf("%s\n", str);
    } else {
        printf("0\n");
    }
}

int main() {
    int n, m;
    n = read_num();
    m = read_num();

    num matrix[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrix[i][j] = read_num();
        }
    }

    num total_score = 0;
    for (int i=0; i<n; i++) {
        total_score += maximum_score(matrix[i], m);
    }

    print_num(total_score);
    return 0;
}