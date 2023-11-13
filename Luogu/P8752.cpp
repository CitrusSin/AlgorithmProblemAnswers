#include <bits/stdc++.h>
using namespace std;

int main() {
    string strs[5];
    for (int i=0; i<5; i++) {
        cin >> strs[i];
    }

    int cnt = 0;
    for (int i=0; i<5; i++) {
        if (strs[i][0] == strs[i][2] && strs[i][3] == strs[i][1]+1) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}