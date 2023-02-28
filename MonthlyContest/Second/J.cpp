#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    int upper = (int)sqrt(n);
    for (int i=2; i<=upper; i++) {
        if (n%i==0) return false;
    }
    return true;
}

bool judge(int n) {
    if ((n&(-n)) == 2) {
        if (n == 2) return true;
        return !is_prime(n/2);
    }
    return n != (n&(-n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        cout << (judge(n)?"haoye!":"crisis!") << endl;
    }
    return 0;
}