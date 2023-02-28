#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int score;
    while (scanf("%d", &score) > 0) {
        const char* str = "Score is error!";
        if (score >= 90 && score <= 100) {
            str = "A";
        } else if (score >= 80 && score <= 89) {
            str = "B";
        } else if (score >= 70 && score <= 79) {
            str = "C";
        } else if (score >= 60 && score <= 69) {
            str = "D";
        } else if (score >= 0 && score <= 59) {
            str = "E";
        }
        printf("%s\n", str);
    }
    return 0;
}