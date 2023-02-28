#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char text[101];
    while (scanf("%s\n", text) == 1) {
        bool need_uppercase = true;
        for (char *ptr = text; *ptr; ptr++) {
            if (*ptr >= 'a' && *ptr <= 'z') {
                if (need_uppercase) {
                    *ptr += 'A' - 'a';
                    need_uppercase = false;
                }
            } else if (*ptr == ' ') {
                need_uppercase = true;
            }
        }

        cout << text << endl;
    }
    return 0;
}