#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palin_transform(char *str, char c) {
    int n = strlen(str);

    if (str[0] != c && str[n-1] != c && str[0] != str[n-1]) {
        return false;
    } else if (n==1) {
        return true;
    } else if (n==2) {
        if (str[0] == str[1]) {
            return true;
        } else if (str[0] == c) {
            str[0] = '\0';
            return true;
        } else if (str[1] == c) {
            str[1] = '\0';
            return true;
        }
        return false;
    } else if (str[0] == str[n-1]) {
        char reserve = str[n-1];
        str[n-1] = '\0';
        bool result = palin_transform(str+1, c);
        str[n-1] = reserve;
        return result;
    }
    
    if (str[0] == c && palin_transform(str+1, c)) {
        str[0] = '\0';
        return true;
    }
    if (str[n-1] == c) {
        str[n-1] = '\0';
        if (palin_transform(str, c)) {
            return true;
        }
        str[n-1] = c;
    }
    return false;
}

int palin_count_internal(char *str) {
    int len = strlen(str);
    if (len == 1) {
        return 0;
    } else if (len == 2 && str[0] == str[1]) {
        return 0;
    } else if (str[0] == str[len-1]) {
        char reserve = str[len-1];
        str[len-1] = '\0';
        int result = palin_count_internal(str+1);
        str[len-1] = reserve;
        return result;
    }

    char buf[len+1];
    int remove_count = 2147483647;

    strcpy(buf, str);
    if (palin_transform(buf, buf[0])) {
        int len2 = 0;
        for (int i=0; i<len; i++) {
            if (buf[i] != '\0') {
                ++len2;
            }
        }
        int r = len - len2;
        if (r < remove_count) {
            remove_count = r;
        }
    }

    strcpy(buf, str);
    if (palin_transform(buf, buf[len-1])) {
        int len2 = 0;
        for (int i=0; i<len; i++) {
            if (buf[i] != '\0') {
                ++len2;
            }
        }
        int r = len - len2;
        if (r < remove_count) {
            remove_count = r;
        }
    }

    if (remove_count == 2147483647) {
        return -1;
    }
    return remove_count;
}

int palin_count(const char *str) {
    int len = strlen(str);
    char buf[len+1];
    strcpy(buf, str);
    return palin_count_internal(buf);
}

int main() {
    char buf_input[100001];
    int n;
    scanf("%d\n", &n);
    
    for (int i=0; i<n; i++) {
        int len;
        scanf("%d\n", &len);
        fgets(buf_input, 100001, stdin);

        int op_count = palin_count(buf_input);
        printf("%d\n", op_count);
    }
    return 0;
}