#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+9;

char a[N], b[N];
int c[N+1] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> a;
    cin >> b;
    
    int ll = 0, lr = strlen(a)-1;
    while (ll < lr) {
        char sw = a[ll];
        a[ll] = a[lr];
        a[lr] = sw;
        ll++;
        lr--;
    }
    ll = 0;
    lr = strlen(b)-1;
    while (ll < lr) {
        char sw = b[ll];
        b[ll] = b[lr];
        b[lr] = sw;
        ll++;
        lr--;
    }
    
    int la = strlen(a), lb = strlen(b);
    for (int offset=0; offset<la; offset++) {
        for (int i=0; i<lb; i++) {
            int result = (a[offset]&0x0f)*(b[i]&0x0f);
            c[offset+i] += result;
        }
    }
    int total_len = la+lb+1;
    for (int i=0; i<total_len; i++) {
        if (c[i] >= 10) {
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
    while (c[total_len-1]==0) total_len--;
    
    if (total_len > 0) {
        for (int i=total_len-1; i>=0; i--) {
            cout.put(c[i] | 0x30);
        }
        cout << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}