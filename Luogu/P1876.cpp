#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    int i = 1;
    while (true) {
        int sq = i*i;
        if (sq<=n) {
            cout << sq << ' ';
            i++;
        } else break;
    }
    cout << endl;
    return 0;
}