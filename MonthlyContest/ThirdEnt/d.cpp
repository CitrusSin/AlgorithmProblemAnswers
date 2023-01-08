// 异或和。。。。
#include <bits/stdc++.h>
using namespace std;

int read_binary() {
    int r = 0;
    char c = cin.get();
    while (c < '0' || c > '1') c = cin.get();
    while (c >= '0' && c <= '1') {
        r <<= 1;
        r += (c&1);
        c = cin.get();
    }
    return r;
}

int judge_internal(int c8, int c4, int c2, int c1, int n) {
    if (c8==0 && c4 == 0 && c2 == 0 && c1 == 0) return 0;
    while (c8 == 0) {
        c8 = c4;
        c4 = c2;
        c2 = c1;
        c1 = 0;
    }
    if (c8 % 2 == 1) {
        return (n-c8)%2==1?-1:1;
    } else {
        return -judge_internal(c4, c2, c1, 0, n);
    }
}

int judge(int boxes[16], int n) {
    int c8=0, c4=0, c2=0, c1=0;
    for (int i=0; i<16; i++) {
        if (i&8) c8 += boxes[i];
        if (i&4) c4 += boxes[i];
        if (i&2) c2 += boxes[i];
        if (i&1) c1 += boxes[i];
    }

    return judge_internal(c8, c4, c2, c1, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int boxes[16] = {};
    for (int i=0; i<n; i++) {
        int b = read_binary();
        if (boxes[b] == 0 || boxes[b] == 2) {
            boxes[b] = 1;
        } else {
            boxes[b] = 2;
        }
    }

    switch (judge(boxes, n)) {
        case 1:
            cout << "hahaha" << endl;
            break;
        case 0:
            cout << "azhe" << endl;
            break;
        case -1:
            cout << "wuwuwu" << endl;
    }
    return 0;
}