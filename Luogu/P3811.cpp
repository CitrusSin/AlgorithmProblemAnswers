#include <bits/stdc++.h>

using namespace std;

void extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    extgcd(b, a%b, x, y);
    int tmp = y;
    y = x-(a/b)*y;
    x = tmp;
}

int inv(int x, int m) {
    // ax+bm=1
    int a, b;
    extgcd(x, m, a, b);
    while (a < 0) a+=m;
    a %= m;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> nums(n, 0);
    for (int i=1; i<=n; i++) {
        if (nums[i-1] == 0) {
            int rev = inv(i, p);
            nums[i-1] = rev;
            if (rev <= n) nums[rev-1] = i;
        }
    }
    for (int i=0; i<n; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}