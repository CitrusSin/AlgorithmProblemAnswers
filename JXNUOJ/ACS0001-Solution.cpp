#include <bits/stdc++.h>
using namespace std;

inline void printchar(int num, char ch){
    for (int i = 0; i < num; i++) printf("%c", ch);
}

signed main(){
    int n, s, len; cin >> n >> s >> len;
    string pattern; cin >> pattern;
    s = (s / 2) + 1;
    for (int i = 0; i < s; i++){
        int charnum1 = 2 * i + 1;
        printchar(s - 1 - i, ' ');
        printchar(charnum1, pattern[0]);
        for(int j = 1; j < n; j++){
            int spacenum = (len - 1) - i * 2, charnum2 = charnum1;
            printchar(spacenum, ' ');
            if(spacenum < 0) charnum2 += spacenum;
            printchar(charnum2, pattern[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < s - 1; i++){
        int charnum1 = 2 * (s - 1 - i) - 1;
        printchar(i + 1, ' ');
        printchar(charnum1, pattern[0]);
        for(int j = 1; j < n; j++){
            int spacenum = (len - 1) - (s - 2 - i) * 2, charnum2 = charnum1;
            printchar(spacenum, ' ');
            if(spacenum < 0) charnum2 += spacenum;
            printchar(charnum2, pattern[j]);
        }
        printf("\n");
    }
    return 0;
}
