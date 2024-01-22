#include <bits/stdc++.h>

using namespace std;

int count_digit(int x) {
    int c = 0;
    while (x != 0) {
        x >>= 1;
        c++;
    }
    return c;
}

int main() {
    int n;
    cin >> n;

    int m = count_digit(n-1);
    cout << m << endl;

    for (int i=0; i<m; i++) {
        vector<int> nums;
        for (int j=0; j<n; j++) {
            if ((j >> i) & 1) {
                nums.push_back(j+1);
            }
        }

        cout << nums.size() << ' ';
        bool fl = true;
        for (int v : nums) {
            if (fl) fl = false; else cout << ' ';
            cout << v;
        }
        cout << endl;
    }

    string v;
    cin >> v;
    int ans = 0;
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        ans *= 2;
        ans += (*it == '1');
    }
    ans++;
    cout << ans << endl;
    return 0;
}