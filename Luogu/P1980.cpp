#include <bits/stdc++.h>
using namespace std;

int quick_itoa(char* strout, int x) {
    if (x == 0) {
        strout[0] = '0';
        strout[1] = '\0';
        return 1;
    } else if (x < 0) {
        strout[0] = '-';
        return quick_itoa(strout+1, -x)+1;
    }

    int cnt = 0;
    char *l = strout, *r = strout;
    while (x > 0) {
        int rem = x%10;
        *r++ = rem | 0x30;
        x /= 10;
        cnt++;
    }
    *r-- = '\0';
    while (l<r) {
        char sw = *l;
        *l = *r;
        *r = sw;
        l++;
        r--;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    char cx = x | 0x30;
    char buf[10];
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        quick_itoa(buf, i);
        for (int k=0; buf[k]; k++) {
            cnt += buf[k]==cx;
        }
    }
    cout << cnt << endl;
    return 0;
}